#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include "irc.hpp"
#include "User.hpp"
#include "Server.hpp"

using std::map;
using std::vector;
using std::string;

class Server;

enum ChannelType
{
	ct_regular = '#',
	ct_local = '&',
};

enum ChannelMode
{
	cm_private = '*',
	cm_public = '=',
	cm_ban = 'b',					// standard mode, only ban user can't join
	cm_limit = 'l',					// l for limited place channel
	cm_invite_only = 'i',
	cm_key = 'k',					// need a key to enter the channel
	cm_moderated = 'm',				// only authorized user can talk in it
	cm_secret = 's',				// channel that only user in it can see
	cm_protected_topic = 't',		// only operator and user can set the topic
	cm_no_external_message = 'n',	// when enabled only user who joined can send private message
};

enum UserChannelMode
{
	um_not_here = 0,
	um_present = ' ',
	um_founder = 'q',
	um_protected = 'a',
	um_operator = 'o',
	um_voice = 'v',
};

typedef map<User *, UserChannelMode>::iterator chan_user_it;
class Channel
{
// Constructors
public:
	Channel(string &name, ChannelType type, string modes, User *owner);
	Channel(string &name, ChannelType type, string modes, User *owner, string &key);

	~Channel();

// Variables
private:
	string							_name;
	ChannelType						_type;
	vector<ChannelMode>				_modes;
	map<User *, UserChannelMode>	_users;
	vector<User *>					_baned;
	string							_topic;
	string							_key;
	string							_topicInfos;
	int								_userLimit;
	std::vector<std::string>		_invited;

// Functions
private:
	void				init(string &modes, User *owner);
	void				rplNames(User *client);
	bool				addMode(char c);
	bool				removeMode(char c);

public:
	//getter
	string				getName() const;
	string				getModes() const;
	string				getTopic() const;
	string				getTopicInfos() const;
	UserChannelMode		getUserChannelMode(User *user);
	char				getStatus() const;
	string				getPrefixMode(User *user);

	//commands
	void				sendMsgAllUsr(User * user, std::string args, std::string msg);
	void				addUser(User *user);
	void				removeUser(User *user);
	void				sendTopic();
	void				who(User *client);
	void				rplNames();
	void				addOperator(User *user);
	void				addOperator();
	void				removeOperator(User *user);

	// bool
	bool				canJoin(User *user, const vector<string>& args) const;
	bool				containUser(User *user) const;
	bool				hasMode(ChannelMode mode) const;
	bool				isInChannel(std::string name);

	//setter
	void				setTopic(string &topic, const string nickName);
	void				setMode(string &modes);
	void				setLimit(string limit);
	void				setKey(string key);

	//static
	static bool			isValidMode(char c);

	//Exceptions
public:
	class BadModeException : public std::exception
	{
	public:
		const char * what() const throw();
	};

	void invite(string nick);
};

#endif