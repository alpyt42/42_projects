#include "irc.hpp"

void	Channel::setMode(string &modes)
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

static bool isValideUserModes(string &modes)
{
	if (modes.empty() || (modes[0] != '-' && modes[0] != '+'))
		return false;
	for (size_t i = 0; i < modes.size(); ++i)
	{
		if (!User::isValidMode(modes[i]) && modes[i] != '+' && modes[i] != '-')
			return false;
	}
	return true;
}

static bool isValideChannelModes(string &modes)
{
	if (modes.empty() || (modes[0] != '-' && modes[0] != '+'))
		return false;
	for (size_t i = 0; i < modes.size(); ++i)
	{
		if (!Channel::isValidMode(modes[i]) && modes[i] != '+' && modes[i] != '-' && modes[i] != 'o')
			return false;
	}
	return true;
}


static bool isValidPositivNum(string &str)
{
	for (size_t i = 0; i < str.size() ; ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool shouldAddMode(string modes, char mode)
{
	bool added = false;
	for (size_t i = 0; i < modes.size(); ++i)
	{
		if (modes[i] == '+')
			added = true;
		if (modes[i] == '-')
			added = false;
		if (modes[i] == mode)
			return added;
	}
	return false;
}

void Channel::setLimit(string limit)
{
	int num = atoi(limit.c_str());
	_userLimit = num;
}

void Channel::addOperator(User *user)
{
	_users[user] = um_operator;
	rplNames();
}

void Channel::removeOperator(User *user)
{
	_users[user] = um_present;
	rplNames();
}

void Channel::setKey(string key)
{
	_key = key;
}

static bool containsDouble(string &str)
{
	for (size_t i = 0; i < str.size() - 1; ++i)
	{
		for (size_t j = i + 1; j < str.size(); ++j)
		{
			if (str[i] == str[j])
				return true;
		}
	}
	return false;
}

void	Server::mode(int clientSocket,  std::vector<std::string> args)
{
	User *client = _users[clientSocket];

	if (args.empty())
		return ERR_NEEDMOREPARAMS(client, "MODE");

	string target = args[0];
	string modes;
	if (args.size() > 1)
		modes = args[1];

	// channel mode
	if (containsKey(_channels, target))
	{
		if (args.size() == 1)
			return RPL_CHANNELMODEIS(client, _channels[target]);
		if (_channels[target]->getUserChannelMode(client) != um_operator)
			return ERR_CHANOPRIVSNEEDED(client, _channels[target]);
		if (!isValideChannelModes(modes))
			return CHANNEL_MESSAGE(client, _channels[target], "Unknown MODE flag", "501");

		if (containsDouble(modes))
			return CHANNEL_MESSAGE(client, _channels[target], "Bad MODE arguments: don't use mode with flags in double", "501");

		if ((shouldAddMode(modes, 'l') && shouldAddMode(modes, 'k')) || (shouldAddMode(modes, 'k') && shouldAddMode(modes, 'o')) || (shouldAddMode(modes, 'o') && shouldAddMode(modes, 'l')))
			return CHANNEL_MESSAGE(client, _channels[target], "Bad MODE arguments: limit (+l), key (+k) and operator (+o) shouldn't be used at the same time", "501");

		// limits
		if (shouldAddMode(modes, 'l'))
		{
			if (args.size() != 3 || !isValidPositivNum(args[2]))
				return CHANNEL_MESSAGE(client, _channels[target], "Bad MODE arguments: limit: use MODE +l <NUMBER>", "501");
			_channels[target]->setLimit(args[2]);
		}

		// key
		if (shouldAddMode(modes, 'k'))
		{
			if (args.size() != 3)
				return CHANNEL_MESSAGE(client, _channels[target], "Bad MODE arguments: key: use MODE +k <password>", "501");
			_channels[target]->setKey(args[2]);
		}

		// operator
		if (shouldAddMode(modes, 'o'))
		{
			if (args.size() == 3 && getUser(args[2]) == NULL)
				return ERR_NOSUCHNICK(client, args[2]);
			if (args.size() != 3 || !_channels[target]->isInChannel(args[2]))
				return CHANNEL_MESSAGE(client, _channels[target], "Bad MODE arguments: operator: use MODE +o <Nickname>", "501");
			_channels[target]->addOperator(getUser(args[2]));
		}
		else if (contains(modes, 'o'))
		{
			if (args.size() == 3 && getUser(args[2]) == NULL)
				return ERR_NOSUCHNICK(client, args[2]);
			if (args.size() != 3 || !_channels[target]->isInChannel(args[2]))
				return CHANNEL_MESSAGE(client, _channels[target], "Bad MODE arguments: operator: use MODE -o <Nickname>", "501");
			_channels[target]->removeOperator(getUser(args[2]));
		}

		_channels[target]->setMode(modes);
		return RPL_CHANNELMODEIS(client, _channels[target]);
	}

	// user mode
	if (userExist(target))
	{
		if (target != client->getNickname() && args.size() < 2)
			return SHORT_MESSAGE(client, "Cant view mode for other users", "502");
		if (target != client->getNickname())
			return SHORT_MESSAGE(client, "Cant change mode for other users", "502");

		if (args.size() < 2)
			return RPL_UMODEIS(client);

		if (!isValideUserModes(modes))
			return SHORT_MESSAGE(client, "Unknown MODE flag", "501");

		client->setMode(modes);
		return RPL_UMODEIS(client);
	}

	// not found
	if (contains(string("&#"), target[0]))
		return ERR_NOSUCHCHANNEL(client, target);
	return ERR_NOSUCHNICK(client, target);
}