#include "irc.hpp"
#include "Channel.hpp"


// Constructors

Channel::Channel(string &name, ChannelType type, string modes, User *owner)
{
	_name = name;
	_type = type;
	_userLimit = -1;
	init(modes, owner);
}

Channel::Channel(string &name, ChannelType type, string modes, User *owner, string &key)
{
	_name = name;
	_type = type;
	_userLimit = -1;
	_key = key;
	init(modes, owner);
}

Channel::~Channel()
{
}

void Channel::init(string &modes, User *owner)
{
	for (size_t i = 0; i < modes.size(); ++i)
	{
		if (!addMode(modes[i]))
			throw BadModeException();
	}
	_users[owner] = um_operator;
}
// Constructors

// Commands
bool Channel::addMode(char c)
{
	if (contains(_modes, ChannelMode(c)))
		return true;
	switch (c)
	{
		case cm_public:					_modes.push_back(cm_public);				return true;
		case cm_private:				_modes.push_back(cm_private);				return true;
		case cm_ban:					_modes.push_back(cm_ban);					return true;
		case cm_limit:					_modes.push_back(cm_limit);					return true;
		case cm_invite_only:			_modes.push_back(cm_invite_only);			return true;
		case cm_key:					_modes.push_back(cm_key);					return true;
		case cm_moderated:				_modes.push_back(cm_moderated);				return true;
		case cm_secret:					_modes.push_back(cm_secret);				return true;
		case cm_protected_topic:		_modes.push_back(cm_protected_topic);		return true;
		case cm_no_external_message:	_modes.push_back(cm_no_external_message);	return true;
		default:																	return false;
	}
}

#define REMOVE(channelType) if(contains(_modes, channelType)) { _modes.erase(std::find(_modes.begin(), _modes.end(), channelType)); return true;} return false;
bool Channel::removeMode(char c)
{
	switch (c)
	{
		case cm_public:					REMOVE(cm_public)
		case cm_private:				REMOVE(cm_private)
		case cm_ban:					REMOVE(cm_ban)
		case cm_limit:					REMOVE(cm_limit)
		case cm_invite_only:			_invited.clear(); REMOVE(cm_invite_only)
		case cm_key:					REMOVE(cm_key)
		case cm_moderated:				REMOVE(cm_moderated)
		case cm_secret:					REMOVE(cm_secret)
		case cm_protected_topic:		REMOVE(cm_protected_topic)
		case cm_no_external_message:	REMOVE(cm_no_external_message)
		default:						return false;
	}
}

bool Channel::isValidMode(char c)
{
	switch (c)
	{
		case cm_public:					return true;
		case cm_private:				return true;
		case cm_ban:					return true;
		case cm_limit:					return true;
		case cm_invite_only:			return true;
		case cm_key:					return true;
		case cm_moderated:				return true;
		case cm_secret:					return true;
		case cm_protected_topic:		return true;
		case cm_no_external_message:	return true;
		default:						return false;
	}
}

void Channel::who(User *client)
{
	for (chan_user_it it = _users.begin(); it != _users.end() ; ++it)
	{
		RPL_WHOREPLY(client, getName(), "H" + (it->second == um_operator ? "*" : ""), it->first);
	}
}

// Commands

// Public Functions
string Channel::getName() const
{
	return _name;
}

void	Channel::sendMsgAllUsr(User * user, std::string cmd, std::string msg)
{
	for (map<User *, UserChannelMode>::iterator it = _users.begin(); it != _users.end(); it++)
	{
		if (user->getNickname() != it->first->getNickname())
			RPL_CMD_CHAN_OTHER(it->first, user, cmd, this, msg);
	}
}

bool Channel::isInChannel(std::string name)
{
	for (chan_user_it it = _users.begin(); it != _users.end(); it++)
		if (it->first->getNickname() == name)
			return true;
	return false;
}

bool Channel::canJoin(User *user, const vector<string>& args) const
{
#ifdef DEBUG
	cerr << YELLOW << "has mode k :" << NC << hasMode(cm_key) << " key: [" << _key << "] arg key: [" << (args.size() > 1 ? args[1] + "]" : "]") << endl;
	cerr << YELLOW << "has mode l :" << NC << hasMode(cm_limit) << " limit: [" << _userLimit << "] actual user nb: [" << _users.size() << "]" << endl;
#endif
	if (hasMode(cm_key) && (args.size() < 2 || args[1] != _key))
	{
		ERR_BADCHANNELKEY(user, this);
#ifdef DEBUG
		cerr << "key" << endl;
#endif
		return false;
	}
	else if (hasMode(cm_ban) && contains(_baned, user))
	{
		ERR_BANNEDFROMCHAN(user, this);
#ifdef DEBUG
		cerr << "ban" << endl;
#endif
		return false;
	}
	else if (hasMode(cm_limit) && int(_users.size()) >= _userLimit)
	{
		ERR_CHANNELISFULL(user, this);
#ifdef DEBUG
		cerr << "limit" << endl;
#endif
		return false;
	}
	else if (hasMode(cm_invite_only) && !contains(_invited, user->getNickname()))
	{
		ERR_INVITEONLYCHAN(user, this);
#ifdef DEBUG
		cerr << "invite" << endl;
#endif
		return false;
	}
	else
		return true;
}

bool Channel::containUser(User *user) const
{
	return containsKey(_users, user);
}

bool Channel::hasMode(ChannelMode mode) const
{
	return contains(_modes, mode);
}

UserChannelMode Channel::getUserChannelMode(User *user)
{
	if (!containUser(user))
		return um_not_here;
	return _users[user];
}

void Channel::addUser(User *user)
{
	if (containsKey(_users, user))
		return;
	_users[user] = um_present;

}

string Channel::getTopic() const
{
	return _topic;
}

string Channel::getModes() const
{
	string modes = "+";
	for (size_t i = 0; i < _modes.size(); ++i)
	{
		if (_modes[i] != cm_private && _modes[i] != cm_public)
			modes += char(_modes[i]);
	}
	return modes;
}

void Channel::setTopic(string &topic, const string nickName)
{
	time_t now = time(NULL);
	char* dt = ctime(&now);
	_topicInfos = nickName + dt;
	_topic = string(topic.substr(1));
}

void Channel::sendTopic()
{
	for (chan_user_it it = _users.begin(); it != _users.end(); ++it)
	{
		if (_topic.empty())
			RPL_NOTOPIC(it->first, this);
		else
			RPL_TOPIC(it->first, this);
	}
}

string Channel::getTopicInfos() const
{
	return _topicInfos;
}

// Public Functions

// Exceptions
const char *Channel::BadModeException::what() const throw()
{
	return "Warning, tried to Add a wrong mode to a channel";
}
// Exceptions

void Channel::removeUser(User *user)
{
	chan_user_it it = _users.find(user);
	if (it != _users.end())
		_users.erase(it);
}

char Channel::getStatus() const
{
	return char(_type);
}

void Channel::rplNames()
{
	for (chan_user_it it = _users.begin(); it != _users.end(); it++)
	{
		rplNames(it->first);
	}
}

void Channel::rplNames(User *client)
{
	for (chan_user_it it = _users.begin(); it != _users.end(); it++)
		RPL_NAMREPLY(client, this, it->first);
	RPL_ENDOFNAME(client, this);
}

string Channel::getPrefixMode(User *user)
{
	if (getUserChannelMode(user) == um_operator)
		return "@";
	return "";
}

void Channel::addOperator()
{
	if (_users.empty() || containsValue(_users, um_operator))
		return;
	_users.begin()->second = um_operator;
}
