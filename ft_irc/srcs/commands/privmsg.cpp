#include "irc.hpp"
#include <unistd.h>

bool Server::checkRudeWords(std::string msg)
{
	size_t rude = msg.find("ntm");
	if (rude != std::string::npos)
		return true;
	rude = msg.find("salope");
	if (rude != std::string::npos)
		return true;
	rude = msg.find("pute");
	if (rude != std::string::npos)
		return true;
	rude = msg.find("sucepute");
	if (rude != std::string::npos)
		return true;
	return false;
}

void	Server::privmsg(int clientSocket, std::vector<std::string> args)
{
	if (args.size() < 2)
		return ERR_NEEDMOREPARAMS(_users[clientSocket], "PRIVMSG");

	std::string target = args[0];
	std::string msg = args[1];

	// channels :
	if (target[0] == '#' || target[0] == '&'|| target[0] == '%')
	{
		if (!containsKey(_channels, target))
			return ERR_NOSUCHCHANNEL(_users[clientSocket], target);

		if (_users[clientSocket]->isInChannel(target))
		{
			if (checkRudeWords(msg))
			{
				std::cout << "!! " << _users[clientSocket]->getNickname() << " s'est fait degager car c'est un gros vilain !!" << std::endl;
				std::vector<std::string> rudeBoy;
				rudeBoy.push_back(target);
				rudeBoy.push_back("gros vilain");
				part(clientSocket, rudeBoy);
			}
			else
				return _users[clientSocket]->sendMsgToChan(target, "PRIVMSG", msg);
		}
		else
		{
			Channel *channel = _channels[args[0]];
			return ERR_NOTONCHANNEL(_users[clientSocket], channel);
		}
	}
	// user :
	else
	{
		User *other = getUser(target);

		if (other == NULL)
			return ERR_NOSUCHNICK(_users[clientSocket], target);

		if (!other->checkstatus())
			return ERR_NOSUCHNICK(_users[clientSocket], target);

		send(clientSocket, "PRIVMSG to " + target + " " + msg + "\r\n");
		RPL_CMD_TARGET(_users[clientSocket], other, "PRIVMSG", msg);
	}
}
