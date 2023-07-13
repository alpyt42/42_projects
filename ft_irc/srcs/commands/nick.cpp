#include "irc.hpp"

static bool isValidNickName(string &nick)
{
	for (size_t i = 0; i < nick.size(); ++i)
	{
		if (contains(string("&#: @%"), nick[i])) return false;
	}
	return true;
}

void	Server::nick(int clientSocket, std::vector<std::string> args)
{
	User *client = _users[clientSocket];

	if (args.empty() || args[0].empty())
		return ERR_NONICKNAMEGIVEN(client);

	if (userExist(args[0]))
		return ERR_NICKNAMEINUSE(client, args[0]);

	if (!isValidNickName(args[0]))
		return ERR_ERRONEUSNICKNAME(client, args[0]);

	RPL_NICK(client, client->getNickname(), args[0]);

	client->setNickname(args[0]);
	client->refreshAllChannels();

	client->nowconnected();
}
