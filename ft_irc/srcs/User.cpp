#include "irc.hpp"
#include "User.hpp"


// Constructors
User::User(int port, sockaddr_in UserAddress) :
	_userSocket(port),
	_userAddress(UserAddress),
	_connected(false)
{
	(void)_userSocket;
	(void)_userAddress;
}

User::~User()
{
}


// getter
std::string	User::getUsername() const
{
	return this->_username;
}

std::string	User::getNickname() const
{
	return this->_nickname;
}

std::string	User::getRealname() const
{
	return this->_realname;
}

int User::getSocket() const
{
	return _userSocket;
}

//setter
void User::setNickname(string &nickName)
{
	_nickname = nickName;
}

void User::setUserNames(string &userName, string &realName)
{
	_realname = realName;
	_username = userName;
}

void	User::setpass(std::string &pass) {
	_pass = pass;
}

//mode
void User::setMode(string &modes)
{
	for (size_t i = 0; i < modes.size(); ++i)
	{
		if (modes[i] == '-')
		{
			for (; i < modes.size(); ++i)
			{
				if (modes[i] == '+')
					break;
				removeMode(modes[i]);
			}
		}
		if (modes[i] == '+')
		{
			for (; i < modes.size(); ++i)
			{
				if (modes[i] == '-')
				{
					--i;
					break;
				}
				addMode(modes[i]);
			}
		}
	}
}

bool User::addMode(char c)
{
	switch (c)
	{
		case u_invisible:		_modes.push_back(u_invisible);	return true;
		case u_operator:		_modes.push_back(u_operator);	return true;
		case u_local_oper:		_modes.push_back(u_local_oper);	return true;
		case u_registered:		_modes.push_back(u_registered);	return true;
		case u_wallops:			_modes.push_back(u_wallops);	return true;
		default:												return false;
	}
}

#define REMOVE(userMode) if(contains(_modes, userMode)) { _modes.erase(std::find(_modes.begin(), _modes.end(), userMode)); return true;} return false;
bool User::removeMode(char c)
{
	switch (c)
	{
		case u_invisible:		REMOVE(u_invisible)
		case u_operator:		REMOVE(u_operator)
		case u_local_oper:		REMOVE(u_local_oper)
		case u_registered:		REMOVE(u_registered)
		case u_wallops:			REMOVE(u_wallops)
		default:						return false;
	}
}

bool User::isValidMode(char c)
{
	switch (c)
	{
		case u_invisible:				return true;
		case u_operator:				return true;
		case u_local_oper:				return true;
		case u_registered:				return true;
		case u_wallops:					return true;
		default:						return false;
	}
}

string User::getModes()
{
	string modes = "+";
	for (size_t i = 0; i < _modes.size(); ++i)
	{
		modes += char(_modes[i]);
	}
	return modes;
}

bool	User::checkstatus() {
	if (_username.size() == 0 || _nickname.size() == 0 || _pass.size() == 0)
		return false;
	return true;
}

void	User::addToChannelList(std::string channelName, Channel* channel)
{
	_channels.insert(std::make_pair(channelName, channel));
}

void	User::removeToChannelList(std::string channelName)
{
	_channels.erase(channelName);
}

void User::partAllChannels()
{
	for (std::map<std::string, Channel*>::iterator it = _channels.begin(); it != _channels.end(); it++)
	{
		RPL_CMD(this, "PART", it->first);
		it->second->sendMsgAllUsr(this, "PART", it->first);
		it->second->removeUser(this);
		it->second->rplNames();
	}
	_channels.clear();
}

void User::refreshAllChannels()
{
	for (std::map<std::string, Channel*>::iterator it = _channels.begin(); it != _channels.end(); it++)
	{
		it->second->rplNames();
	}
}

void	User::sendMsgToChan(std::string channelName,  std::string cmd, std::string msg)
{
	for (std::map<std::string, Channel*>::iterator it = _channels.begin(); it != _channels.end(); it++)
	{
		if (it->first == channelName)
			return it->second->sendMsgAllUsr(this, cmd, msg);
	}
}

bool User::isInChannel(std::string channelName)
{
	std::map<std::string, Channel*>::iterator it = _channels.find(channelName);
	if (it != _channels.end())
		return true;
	return false;
}

bool User::hasMode(UserMode mode)
{
	return contains(_modes, mode);
}

bool	User::getConnection() const {
	return _connected;
}

void	User::setConnectionON() {
	_connected = true;
}

void	User::nowconnected() {
	if (!getConnection() && checkstatus()) {
		std::cout << BGREEN << "'" << getNickname() << "' is now connected to ircserv!" << NC << endl;
		send(_userSocket, "> You're now connected <\r\n");
		setConnectionON();
	}
}

bool User::hasPass() const
{
	return !_pass.empty();
}
