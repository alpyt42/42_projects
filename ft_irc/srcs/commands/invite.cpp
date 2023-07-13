#include "irc.hpp"
#include "numerics.h"

void Channel::invite(string nick)
{
	_invited.push_back(nick);
}

void	Server::invite(int clientSocket, std::vector<std::string> args)
{
	// args format waited :
	// arg[0] = Other_User_Name
	// arg[1] = Channel_Name
	User *client = _users[clientSocket];

	if (args.size() < 2)
		return ERR_NEEDMOREPARAMS(client, "INVITE");

	if (args.size() > 2)
		return ERR_UNKNOWNERROR(client, "INVITE");

	if (!userExist(args[0]))
		return ERR_NOSUCHNICK(client, args[0]);
	
	if (!getUser(args[0])->checkstatus())
		return ERR_NOSUCHNICK(client, args[0]);

	if (!containsKey(_channels, args[1]))
		return ERR_NOSUCHCHANNEL(client, args[1]);

	Channel *channel = _channels[args[1]];

	if (!channel->containUser(client))
		return ERR_NOTONCHANNEL(client, channel);

	if (channel->hasMode(cm_invite_only) && channel->getUserChannelMode(client) != um_operator)
		return ERR_CHANOPRIVSNEEDED(client, channel);

	if (channel->isInChannel(args[0]))
		return ERR_USERONCHANNEL(client, channel, args[0]);

	channel->invite(args[0]);
	send(getUser(args[0])->getSocket(), "You have been invited in the channel " + channel->getName() + "\r\n");
	RPL_INVITING(client, channel, args[0]);
}
