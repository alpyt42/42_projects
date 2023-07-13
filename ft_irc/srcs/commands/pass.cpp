#include "irc.hpp"

void Server::pass(int clientSocket, std::vector<std::string> args)
{
	User *user = _users[clientSocket];

	if (args.empty())
		return ERR_NEEDMOREPARAMS(user, "PASS");

	if (user->hasPass())
		return ERR_ALREADYREGISTERED(user);

	std::string password = args[0];
	if (password != _password)
		return ERR_PASSWDMISMATCH(user);

	user->setpass(_password);
	user->nowconnected();
}
