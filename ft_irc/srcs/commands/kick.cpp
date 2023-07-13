#include "irc.hpp"

bool	Server::userExist(std::string nickname)
{
	for (std::map<int, User*>::iterator it = _users.begin(); it != _users.end(); it++)
		if (it->second->getNickname() == nickname)
			return true;
	return false;
}

void	Server::kick(int clientSocket, std::vector<std::string> args) {
	if (args.size() < 2)
		return ERR_NEEDMOREPARAMS(_users[clientSocket], "KICK");
	if (args.size() > 3)
		return ERR_UNKNOWNERROR(_users[clientSocket], "KICK");
	if (args.size() == 3)
	{
		args.erase(args.begin());
		args[1] = string(args[1].substr(1));
	}
	std::string userName = args[1];
	std::map<std::string, Channel*>::iterator it = _channels.find(args[0]);
	if (it != _channels.end())
	{
		if (it->second->getUserChannelMode(_users[clientSocket]) == um_operator)
		{
			if (!it->second->containUser(_users[clientSocket]) || !it->second->isInChannel(userName))
				return ERR_NOTONCHANNEL(_users[clientSocket], it->second);

			std::vector<std::string> channels;
			channels.push_back(args[0]);
			User *user = getUser(userName);
			RPL_CMD(user, "KICK",  it->first);
			part(user->getSocket(), channels);
		}
		else return ERR_CHANOPRIVSNEEDED(_users[clientSocket], it->second);
	}
	else return ERR_NOSUCHCHANNEL(_users[clientSocket], args[0]);
}
