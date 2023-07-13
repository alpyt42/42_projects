#include "irc.hpp"
#include "numerics.h"

void	Server::who(int clientSocket, std::vector<std::string> args)
{
	User *client = _users[clientSocket];

	if (args.empty())
		return ERR_NEEDMOREPARAMS(client, "WHO");

	// if mask is a channel name
	if (containsKey(_channels, args[0]))
	{
		Channel *channel = _channels[args[0]];
		channel->who(client);
		return RPL_ENDOFWHO(client, args[0]);
	}

	if (args[0][0] == '#' || args[0][0] == '&')
		return ERR_NOSUCHSERVER(client, args[0]);

	User *user = getUser(args[0]);
	if (user == NULL)
		return ERR_NOSUCHSERVER(client, args[0]);

	if (user->hasMode(u_invisible))
		return ERR_NOSUCHNICK(client, args[0]);

	RPL_WHOREPLY(client, "*", "H", user);
	return RPL_ENDOFWHO(client, args[0]);
}