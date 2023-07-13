#include "irc.hpp"

int	main(int ac, char **av)
{
	std::string	password = "";
	int			port = 0;
	struct sigaction	action;

	(void)action;
	if (ac >= 2)
		port = atof(av[1]);
	if (ac >= 3)
		password = std::string(av[2]);
	if (!check_input(ac, port, password))
		return 1;
	Server	server(port, password);
	try
	{
		server.init();
	}
	catch(const std::exception& e)
	{
		std::cerr << BRED << e.what() << NC << std::endl;
		return 2;
	}
	signal(SIGINT, &Server::ctrlc);
	server.exe();
	return 0;
}
