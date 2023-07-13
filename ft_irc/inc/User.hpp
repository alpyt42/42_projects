#ifndef USER_HPP
# define USER_HPP

#include "irc.hpp"
class Channel;

enum UserMode
{
	u_invisible = 'i',
	//This mode is standard, and the mode letter used for it is "+i".
	//If a user is set to ‘invisible’, they will not show up in commands
	// such as WHO or NAMES unless they share a channel with the user that
	// submitted the command. In addition, some servers hide all channels
	// from the WHOIS reply of an invisible user they do not share
	// with the user that submitted the command.

	u_operator = 'o',
	//This mode is standard, and the mode letter used for is it "+o".
	//If a user has this mode, this indicates that they are a network operator.

	u_local_oper = 'O',
	//This mode is standard, and the mode letter used for it is "+O".
	//If a user has this mode, this indicates that they are a server operator.
	// A local operator has operator privileges for their server, and not for the rest of the network.

	u_registered = 'r',
	//This mode is widely-used, and the mode letter used for it is typically "+r".
	// The character used for this mode, and whether it exists at all, may vary depending on server software and configuration.
	//If a user has this mode, this indicates that they have logged into a user account.

	u_wallops = 'w',
	//This mode is standard, and the mode letter used for it is "+w".
};

class User
{
// Constructors
public:
	User(int port, sockaddr_in UserAddress);
	~User();

// Variables
private:
	int									_userSocket;
	sockaddr_in							_userAddress;
	std::string							_username;
	std::string							_pass;
	std::string							_realname;
	std::string							_nickname;
	bool								_connected;
	std::map<std::string, Channel*>		_channels;
	std::vector<UserMode>				_modes; // contains names of privmsg

public:
	std::string			buffSocket;

// Functions
public:
	// getter
	std::string			getUsername() const;
	std::string			getNickname() const;
	bool				getConnection() const;
	std::string			getRealname() const;
	std::string			getModes();
	int					getSocket() const;
	bool				hasPass() const;
	bool				hasMode(UserMode mode);
	//setter
	void				setNickname(std::string &nickName);
	void				setConnectionON();
	void				setpass(std::string &pass);
	void				setUserNames(std::string &userName, std::string &realName);
	void				setMode(std::string &modes);
	void				addToChannelList(std::string channelName, Channel* channel);
	void				removeToChannelList(std::string channelName);
	//commands
	void				sendMsgToChan(std::string channelName, std::string cmd, std::string msg);
	bool 				isInChannel(std::string channelName);
	void				partAllChannels();
	bool				checkstatus();
	void				nowconnected();
	void				refreshAllChannels();

private:
	bool				addMode(char c);
	bool				removeMode(char c);

public:
	static bool			isValidMode(char c);
};

#endif