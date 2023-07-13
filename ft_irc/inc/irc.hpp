#ifndef IRC_HPP
# define IRC_HPP

#include "numerics.h"
#include "utils.hpp"
#include "Channel.hpp"
#include "User.hpp"
#include "Server.hpp"

# define BUFFER_SIZE 1000

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;

int			print_error(std::string message);
int			check_input(int ac, int port, std::string password);
void		displaycmd(std::string cmdName, std::vector<std::string> args);
void		split(const std::string& input, const std::string& del, std::vector<std::string>& tokens);
void		splitOnDots(const std::string& input, const std::string& del, std::vector<std::string>& tokens);
std::string	strtoupper(const std::string& str);
void		send(int socket, string message);

// template that checks if the value is contained in the Container
template <typename Tc, typename Tv>
bool		contains(Tc container, Tv value)
{
	return std::find(container.begin(), container.end(), value) != container.end();
}

template <typename Tc, typename Tk>
bool		containsKey(Tc container, Tk value)
{
	return container.find(value) != container.end();
}

template <typename Tc, typename Tv>
bool		containsValue(Tc container, Tv value)
{
	for (typename Tc::iterator it = container.begin(); it != container.end(); it++)
	{
		if (it->second == value)
			return true;
	}
	return false;
}

#endif