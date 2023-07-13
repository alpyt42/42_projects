#include "irc.hpp"

void	Server::quit(int clientSocket, std::vector<std::string> args)
{
	std::string reason;

	if (!args.empty() && args[0][0] != '\0')
		reason = args[0];
	else
		reason = "leaving";

	std::string msg = "Quit " + reason;
	std::map<int, User*>::iterator it = _users.find(clientSocket);

	if (it != _users.end())
	{
		std::cout << BMAGENTA "Client disconnected." NC << " Client socket: " << clientSocket << ", reason :" << reason << std::endl;
		_users[clientSocket]->partAllChannels();
		for (size_t i = 0; i < _fds.size(); i++) {
			if (_fds[i].fd == clientSocket) {
				_fds.erase(_fds.begin() + i);
				break;
			}
		}
		delete _users[clientSocket];
		_users.erase(clientSocket);
		close(clientSocket);
	}
}
