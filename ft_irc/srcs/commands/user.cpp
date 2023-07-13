#include "irc.hpp"

bool Server::userExistUserName(string &userName)
{
	for (user_it it = _users.begin(); it != _users.end(); it++)
	{
		if (it->second->getUsername() == userName)
			return true;
	}
	return false;
}

void	Server::user(int clientSocket, std::vector<std::string> args)
{
	User *client = _users[clientSocket];

	if (args.size() < 4)
		return ERR_NEEDMOREPARAMS(client, "USER");

	if (args[1] != "0" || args[2] != "*")
		return ERR_UNKNOWNERROR(client, "USER");

	if (userExistUserName(args[0]))
		return ERR_ALREADYREGISTERED(client);

	if (args[3][0] && args[3][0] == ':')
		args[3] = args[3].substr(1);
	client->setUserNames(args[0], args[3]);

	string message = client->getNickname() SPACE "set user name to" SPACE client->getUsername() SPACE "and real name to" SPACE client->getRealname();
	send(clientSocket, message + "\r\n");
	client->nowconnected();
}
