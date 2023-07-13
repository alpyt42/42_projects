#include "irc.hpp"

void	Server::part(int clientSocket, std::vector<std::string> args)
{
	std::string msg = "leaving";

	if (args.empty())
		return ERR_NEEDMOREPARAMS(_users[clientSocket], "PART");

	if (args.size() >= 1)
	{
		std::vector<std::string> chanList;
		split(args[0], ",", chanList);
		for (size_t i = 0; i < chanList.size(); i++)
		{
			std::map<std::string, Channel*>::iterator it = _channels.find(chanList[i]);
			if (it != _channels.end())
			{
				if (!it->second->containUser(_users[clientSocket])) 
					return ERR_NOTONCHANNEL(_users[clientSocket], it->second);
				if (args.size() == 2)
					msg = args[1];
				CHANNEL_MESSAGE(_users[clientSocket], it->second, "PART: " + msg, "");
				RPL_CMD(_users[clientSocket], "PART",  chanList[i]);
				it->second->sendMsgAllUsr(_users[clientSocket], "PART", msg);
				it->second->removeUser(_users[clientSocket]);
				_users[clientSocket]->removeToChannelList(chanList[i]);
				it->second->addOperator();
				it->second->rplNames();
			}
			else return ERR_NOSUCHCHANNEL(_users[clientSocket], chanList[i]);
		}
	}
}
