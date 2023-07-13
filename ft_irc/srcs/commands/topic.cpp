#include "irc.hpp"

void	Server::topic(int clientSocket, std::vector<std::string> args)
{
	User *client = _users[clientSocket];

	if (args.empty())
		return ERR_NEEDMOREPARAMS(client, "TOPIC");

	if (!containsKey(_channels, args[0]))
		return ERR_NOSUCHCHANNEL(client, args[0]);

	Channel *channel = _channels[args[0]];

	if (!channel->containUser(client))
		return ERR_NOTONCHANNEL(client, channel);

	if (args.size() == 1)
		return RPL_TOPIC(client, channel);

	if (channel->hasMode(cm_protected_topic) && channel->getUserChannelMode(client) != um_operator)
		return ERR_CHANOPRIVSNEEDED(client, channel);

	if (args[1][0] != ':')
		return ERR_UNKNOWNERROR(client, "TOPIC");

	channel->setTopic(args[1], client->getNickname());
	channel->sendTopic();
	return RPL_TOPICWHOTIME(client, channel);
}