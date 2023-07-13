#ifndef SERVER_HPP
# define SERVER_HPP

#include "irc.hpp"

class Channel;
class User;

class Server
{
	typedef void (Server::*FuncPtr)(int, std::vector<std::string>);
	typedef std::map<int, User*>::iterator user_it;
	typedef std::map<std::string, Channel*>::iterator channel_it;

// Constructors
public:
	Server(int port, const std::string& password);
	~Server();
	static void	ctrlc(int sig);


// Variables
private:
	int								_port;
	std::string						_password;
	int								_serverSocket;
	sockaddr_in						_serverAddress;
	std::vector<pollfd>				_fds;
	std::map<int, User*>			_users;
	std::map<std::string, FuncPtr>	_commandMap;
	std::map<std::string, Channel*>	_channels;
	static bool						_runtime;

// Functions
public:
	void		init();
	void		exe();
	void		allQuit();


	bool		userExist(std::string nickname);
	bool		userExistUserName(std::string &userName);
	User		*getUser(std::string &nickName);

	// statics
	static void	sendMessageTo(const User *client, const std::string& msg);


	// commands
private:
	void		pass(int clientSocket, std::vector<std::string> args);
	void		nick(int clientSocket, std::vector<std::string> args);
	void		user(int clientSocket, std::vector<std::string> args);
	void		quit(int clientSocket, std::vector<std::string> args);
	void		privmsg(int clientSocket, std::vector<std::string> args);
	void		join(int clientSocket, std::vector<std::string> args);
	void		who(int clientSocket, std::vector<std::string> args);
	void		part(int clientSocket, std::vector<std::string> args);
	void		invite(int clientSocket, std::vector<std::string> args);
	void		topic(int clientSocket, std::vector<std::string> args);
	void		kick(int clientSocket, std::vector<std::string> args);
	void		mode(int clientSocket, std::vector<std::string> args);
	void		welcome(int clientSocket, std::vector<std::string> args);

	// exec
	void		_adduser();
	void		_disconnectuser(int clientSocket, std::string reason);
	void		parseCommand(const std::string& command, int clientSocket);

	//commands parts
	void 		sendCommand(int client, std::string cmdName, std::vector<std::string> args);

	bool 		checkRudeWords(std::string msg);
};

#endif
