#include "irc.hpp"

int print_error(std::string message) {
	if (message.size() == 0) {
		std::cerr << RED << "Error\n" << NC;
		return 0;
	}
	else
		std::cerr << RED << "Error : " << message << NC << std::endl;
	return 0;
}

int	check_input(int ac, int port, std::string password) {
	if (ac != 3)
		return (print_error("Please provide: ./ircserv <port> <password>"));
	else if (port <= 1024 || port >= 65536)
		return (print_error("Port must be between 1024 & 65536"));
	else if (password.size() == 0)
		return (print_error("Password should not be empty"));
	return 1;
}

void displaycmd(std::string cmdName, std::vector<std::string> args) {
	std::cout << "Command name: " << cmdName << "\t\t";
	if (args.empty())
	{
		cout << endl;
		return;
	}
	std::cout << "Args: ";
	for (size_t i = 0; i < args.size(); ++i) {
		std::cout << args[i];
		if (i != args.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl << std::endl;
}

void splitOnDots(const std::string& input, const std::string& del, std::vector<std::string>& tokens)
{
	std::string::size_type pos = 0;
	std::string::size_type prevPos = 0;
	while ((pos = input.find_first_of(del, prevPos)) != std::string::npos) {
		std::string line = input.substr(prevPos, pos - prevPos);
		if (!line.empty()) {
			tokens.push_back(line);
		}
		prevPos = pos + 1;
		if (input[prevPos] == ':') {
			std::string line = input.substr(prevPos);
			if (!line.empty()) {
				tokens.push_back(line);
			}
			return;
		}
	}
	std::string lastLine = input.substr(prevPos);
	if (!lastLine.empty()) {
		tokens.push_back(lastLine);
	}
}

void split(const std::string& input, const std::string& del, std::vector<std::string>& tokens)
{
	std::string::size_type pos = 0;
	std::string::size_type prevPos = 0;
	while ((pos = input.find_first_of(del, prevPos)) != std::string::npos) {
		std::string line = input.substr(prevPos, pos - prevPos);
		if (!line.empty()) {
			tokens.push_back(line);
		}
		prevPos = pos + 1;
	}
	std::string lastLine = input.substr(prevPos);
	if (!lastLine.empty()) {
		tokens.push_back(lastLine);
	}
}

std::string strtoupper(const std::string& str) {
	std::string result = str;
	for (size_t i = 0; i < result.length(); ++i) {
		result[i] = std::toupper(result[i]);
	}
	return result;
}

void send(int socket, string message)
{
	send(socket, message.c_str(), message.size(), 0);
}