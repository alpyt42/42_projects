#include "irc.hpp"
#include "Channel.hpp"
#include "numerics.h"

static bool isValideChannelName(const string &name)
{
	if (name.size() < 2)
		return false;
	if (name[0] != '#' && name[0] != '&')
		return false;
	for (size_t i = 1; i < name.size(); ++i)
	{
		if (contains(string("#&: "), name[i]))
			return false;
	}
	return true;
}

void	Server::join(int clientSocket,  std::vector<std::string> args)
{
	User *client = _users[clientSocket];
	Channel *channel;

	if (args.empty())
		return ERR_NEEDMOREPARAMS(client, "JOIN");

	if (args.size() > 2)
		return ERR_UNKNOWNERROR(client, "JOIN");

	if (args[0] == "0")
		return client->partAllChannels();

	if (!isValideChannelName(args[0]))
		return ERR_UNKNOWNERROR(client, "JOIN");

	if (!containsKey(_channels, args[0]))
	{
		if (args.size() == 1)
			channel = new Channel(args[0], ChannelType(args[0][0]), std::string("=bt"), client);
		else
			channel = new Channel(args[0], ChannelType(args[0][0]), std::string("=bt"), client, args[1]);
		_channels[channel->getName()] = channel;
	}
	else
	{
		channel = _channels[args[0]];
	}

	if (!channel->canJoin(client, args))
		return;
	channel->addUser(client);
	client->addToChannelList(channel->getName(), channel);

	RPL_CMD(client, "JOIN", channel->getName());
	if (!channel->getTopic().empty())
		RPL_TOPIC(client, channel);
	channel->rplNames();
}
