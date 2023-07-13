#include "irc.hpp"
#include "Server.hpp"

bool Server::_runtime = true;

// Constructors
Server::Server(int port, const std::string& password) :
	_port(port),
	_password(password),
	_serverSocket(socket(AF_INET, SOCK_STREAM, 0))
{
}

Server::~Server() {}
// Constructors

// Functions Public
void	Server::init() {
	std::cout << BWHITE << "Server initialization on port " << BLUE << _port << NC << std::endl;
	std::cout << BWHITE << "Password : " << YELLOW << _password << NC << std::endl;
	if (_serverSocket == -1) {
		throw std::runtime_error("Server socket creation error");
	}
	// Server address and port configuration
	_serverAddress.sin_family = AF_INET; // Set the address family to IPv4
	_serverAddress.sin_addr.s_addr = INADDR_ANY; // Set the IP address to any available network interface on the host
	_serverAddress.sin_port = htons(_port); // Set the port number in network byte order
	// Server socket address and port association
	if (bind(_serverSocket, (struct sockaddr*)&_serverAddress, sizeof(_serverAddress)) == -1)
	{
		close(_serverSocket);
		throw std::runtime_error("Error associating address and port to server socket");
	}
	// Socket listening for incoming connections
	if (listen(_serverSocket, 128) == -1) {
		close(_serverSocket);
		throw std::runtime_error("Server socket listening error");
	}
	pollfd serverPollfd;
	serverPollfd.fd = _serverSocket;
	serverPollfd.events = POLLIN;
	_fds.push_back(serverPollfd);
	std::cout << BGREEN << "Server successfully initialized!" << NC << std::endl;
}

void Server::exe() {
	std::cout << BBLUE << "\n> Server running..." << NC << std::endl;
	while (_runtime) {
		int numReady = poll(&_fds[0], _fds.size(), -1);
		if (_runtime == false) {
			allQuit();
			return;
		}
		if (numReady  == -1)
			perror(NULL);
		if (_fds[0].revents & POLLIN) {
			_adduser();
			numReady--;
		}
		for (size_t i = 1; i < _fds.size() && numReady > 0; ++i) {
			if (_fds[i].revents & POLLIN) {
				char buffer[BUFFER_SIZE + 1];
				memset(&buffer, 0, BUFFER_SIZE + 1);
				User *user = _users[_fds[i].fd];
				ssize_t bytesRead = recv(_fds[i].fd, buffer, sizeof(buffer), 0);
				if (bytesRead > 0) {
					std::string message(buffer, bytesRead);
					std::cout << "Received from " << (containsKey(_users, _fds[i].fd) ? _users[_fds[i].fd]->getNickname() : string("") + char(_fds[i].fd + '0')) << " : " << message;
					user->buffSocket += std::string(buffer);
					size_t	pos = 0;
					int		siz = 1;
					if ((pos = user->buffSocket.find("\n")) != std::string::npos) {
						if (user->buffSocket[pos - 1] == '\r') {
							pos--;
							siz++;
						}
						std::string copycmd = string(user->buffSocket);
						user->buffSocket.clear();
						parseCommand(copycmd, _fds[i].fd);
					}

				} else if (bytesRead <= 0) {
					if (bytesRead < 0)
						std::cout << "recv() error: " << strerror(errno) << std::endl;
					_disconnectuser(_fds[i].fd, "leaving");
					i--;
					break;
				}
				numReady--;
			}
		}
		if (_runtime == false)
			allQuit();
	}
}

User *Server::getUser(string &nickName)
{
	for (user_it it = _users.begin(); it != _users.end(); it++)
	{
		if (it->second->getNickname() == nickName)
		{
			return it->second;
		}
	}
	return NULL;
}
// Functions Public

//exec
void	Server::_adduser()
{
	sockaddr_in clientAddress;
	socklen_t clientAddressLength = sizeof(clientAddress);
	int clientSocket = accept(_serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLength);
	if (clientSocket == -1)
	{
		print_error("Error accepting client connection");
		return ;
	}
	pollfd clientPollfd;
	clientPollfd.fd = clientSocket;
	clientPollfd.events = POLLIN;
	clientPollfd.revents = 0;
	User *newUser = new(std::nothrow)User(clientSocket, clientAddress);
	if (newUser)
	{
		_users[clientSocket] = newUser;
		std::cout << BCYAN "Client connected." NC << " Client socket: " << clientSocket << std::endl;
	} else
		print_error("Error creating client");
	_fds.push_back(clientPollfd); // Add the client socket to the pollfd table
}

void	Server::_disconnectuser(int clientSocket, std::string reason)
{
	std::vector<std::string> reasons;
	if (reason.empty())
		reason = "empty_reason";
	reasons.push_back(reason);
	quit(clientSocket, reasons);
}

void	Server::parseCommand(const std::string& command, int clientSocket)
{
	std::vector<std::string> commands;
	split(command, "\r\n", commands);
	for (std::vector<std::string>::iterator it = commands.begin(); it != commands.end(); ++it)
	{
		std::vector<std::string> tokens;
		std::string commandName;
		std::vector<std::string> commandArgs;
		splitOnDots(*it, " ", tokens);
		if (!tokens.empty()) {
			commandName = tokens[0];
			commandArgs.assign(tokens.begin() + 1, tokens.end());
		}
		displaycmd(strtoupper(commandName), commandArgs);
		if (_users.find(clientSocket) != _users.end())
			sendCommand(clientSocket, strtoupper(commandName), commandArgs);
		else
			return ;
	}
}

void Server::welcome(int clientSocket, std::vector<string> args)
{
	(void)args;
	if (!_users[clientSocket]->checkstatus())
		send(clientSocket, "Welcome to IRC !\nTo connect to this server you need to enter:\nPASS <password>\nNICK <nick>\nUSER <username> 0 * :<realname>\r\n");
}

void Server::sendCommand(int client, string cmdName, std::vector<string> args)
{
	User *userptr = _users[client];
	string cmdNames[16] = {"PASS", "NICK", "USER", "QUIT", "PRIVMSG", "JOIN", "WHO", "PART", "INVITE", "TOPIC", "KICK", "MODE", "CAP"};
	int i = 0;
	for (; i < 16; ++i)
	{
		if (cmdNames[i] == cmdName)
			break;
	}
	if (!_users[client]->checkstatus() && cmdName != "PASS" && cmdName != "USER" && cmdName != "NICK" && cmdName != "CAP") {
		std::stringstream ss;
		ss << "Client (socket " << client << ") is not connected.\n";
		std::string message = ss.str();
		send(client, message.c_str(), message.length(), 0);
		return ;
	}
	switch (i)
	{
		case 0:			return pass(client, args);
		case 1:			return nick(client, args);
		case 2:			return user(client, args);
		case 3:			return quit(client, args);
		case 4:			return privmsg(client, args);
		case 5:			return join(client, args);
		case 6:			return who(client, args);
		case 7:			return part(client, args);
		case 8:			return invite(client, args);
		case 9:			return topic(client, args);
		case 10:		return kick(client, args);
		case 11:		return mode(client, args);
		case 12:		return welcome(client, args);
		default:		ERR_UNKNOWNCOMMAND(userptr, cmdName);
	}
}
//exec

//static Functions

void Server::sendMessageTo(const User *client, const std::string &msg)
{
	size_t byteSent = 0;
	while (byteSent < msg.length())
	{
		long len = send(client->getSocket(), msg.c_str(), msg.length(), 0x4000);
		if (len < 0)
		{
			std::cerr << "send() error: server to client" << std::endl;
			break ;
		}
		byteSent += len;
	}
}

void	Server::ctrlc(int sig)
{
	(void)sig;
	_runtime = false;
}

void	Server::allQuit()
{
	// del users
	std::map<int, User*>::iterator it2 = _users.begin();
	std::map<int, User*>::iterator it;
	while (it2 != _users.end())
	{
		it = it2++;
		if (it->second->getNickname().empty())
			std::cout << "Socket: " << BRED << it->second->getSocket() << NC << " has quit\n";
		else
			std::cout << BRED << it->second->getNickname() << NC << " has quit\n";
		_disconnectuser(it->second->getSocket(), "Leaving");
	}
	// del channels
	std::map<std::string, Channel*>::iterator it3 = _channels.begin();
	std::map<std::string, Channel*>::iterator it4;
	while (it3 != _channels.end())
	{
		it4 = it3++;
		std::cout << "Channel " << BRED << it4->first << NC << " has been deleted\n";
		delete it4->second;
	}
	close(_serverSocket);
}