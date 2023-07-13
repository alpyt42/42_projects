#ifndef IRC_NUMERICS_H
#define IRC_NUMERICS_H

#define IP_ADDR "127.0.0.1"
#define SERVER_NAME "localhost"

#define SEND Server::sendMessageTo(
#define RN + "\r\n")
#define SPACE + " " +
#define SERVER(num) std::string(":localhost") SPACE num

#define SHORT_MESSAGE(client, message, num) \
SEND client, SERVER(num) + ((std::string(num)).empty() ? "" : " ") + client->getNickname() SPACE ":" + message RN

#define BASIC_MESSAGE(client, arg, message, num) \
SEND client, SERVER(num) + ((std::string(num)).empty() ? "" : " ") + client->getNickname() SPACE arg SPACE ":" + message RN

#define CHANNEL_MESSAGE(client, channel, message, num) \
SEND client, SERVER(num) + ((std::string(num)).empty() ? "" : " ") + client->getNickname() SPACE channel->getName() SPACE ":" + message RN


// 0
# define RPL_CMD(client, cmd, msg) \
SEND client, ":" + client->getNickname() + "!" + client->getUsername() + "@" + IP_ADDR SPACE cmd SPACE msg RN

// nick
# define RPL_NICK(client, oldNick, newNick) \
SEND client, ":" + oldNick + "!" + client->getUsername() + "@" + IP_ADDR SPACE "NICK" SPACE newNick RN

// privmsg
# define RPL_CMD_CHAN_OTHER(client, other, cmd, channel, msg) \
SEND client, ":" + other->getNickname() + "!" + other->getUsername() + "@" + IP_ADDR SPACE cmd SPACE channel->getName() SPACE msg RN

# define RPL_CMD_TARGET(client, target, cmd, msg) \
SEND target, ":" + client->getNickname() + "!" + client->getUsername() + "@" + IP_ADDR SPACE cmd SPACE ":" SPACE msg RN

// 221
# define RPL_UMODEIS(client) \
SEND client, SERVER("221") SPACE client->getNickname() SPACE client->getModes() RN

// 315
# define RPL_ENDOFWHO(client, mask) BASIC_MESSAGE(client, mask, "End of WHO list", "315")

// 324
# define RPL_CHANNELMODEIS(client, channel) \
SEND client, SERVER("324") SPACE client->getNickname() SPACE channel->getName() SPACE channel->getModes() RN

// 331
# define RPL_NOTOPIC(client, channel) CHANNEL_MESSAGE(client, channel, "No topic is set", "331")

// 332
# define RPL_TOPIC(client, channel) CHANNEL_MESSAGE(client, channel, channel->getTopic(), "332")

// 333
# define RPL_TOPICWHOTIME(client, channel) \
SEND client, SERVER("333") SPACE client->getNickname() SPACE channel->getName() SPACE channel->getTopicInfos() RN

// 352
# define RPL_WHOREPLY(client, channel, flag, user) \
SEND client, SERVER("352") SPACE client->getNickname() SPACE channel SPACE user->getUsername() SPACE SERVER_NAME SPACE IP_ADDR SPACE user->getNickname() \
SPACE flag SPACE ":1" SPACE user->getRealname() RN

// 353
# define RPL_NAMREPLY(client, channel, user) \
SEND client, SERVER("353") SPACE client->getNickname() SPACE channel->getStatus() SPACE channel->getName() SPACE ":" + channel->getPrefixMode(user) + \
user->getNickname() RN

// 341
# define RPL_INVITING(client, channel, userName) \
SEND client, ":" + client->getNickname() + "!" + client->getUsername() + "@" + IP_ADDR SPACE "INVITE" SPACE userName SPACE channel->getName() RN

// 366
# define RPL_ENDOFNAME(client, channel) CHANNEL_MESSAGE(client, channel, "End of /NAMES list", "366")

// 400
# define ERR_UNKNOWNERROR(client, cmd) BASIC_MESSAGE(client, cmd, "Wrong arguments", "400")

// 401
# define ERR_NOSUCHNICK(client, nickName) BASIC_MESSAGE(client, nickName, "No such nick", "401")

//402
# define ERR_NOSUCHSERVER(client, serverName) BASIC_MESSAGE(client, serverName, "No such server", "402")

// 403
# define ERR_NOSUCHCHANNEL(client, channelName) BASIC_MESSAGE(client, channelName, "No such channel", "403")

// 421
# define ERR_UNKNOWNCOMMAND(client, cmd) BASIC_MESSAGE(client, cmd, "Unknown command", "421")

//431
# define ERR_NONICKNAMEGIVEN(client) SHORT_MESSAGE(client, "No nickname given", "431")

// 432
# define ERR_ERRONEUSNICKNAME(client, nickName) BASIC_MESSAGE(client, nickName, "Erroneus nickname", "432")

//433
# define ERR_NICKNAMEINUSE(client, nickName) BASIC_MESSAGE(client, nickName, "Nickname is already in use", "433")

//441
#define ERR_USERNOTINCHANNEL(client, nickName) BASIC_MESSAGE(client, nickName, "you're not in channel", "441")

// 442
# define ERR_NOTONCHANNEL(client, channel) CHANNEL_MESSAGE(client, channel, "You're not on that channel", "442")

// 443
# define ERR_USERONCHANNEL(client, channel, nick) \
SEND client, SERVER("443") SPACE client->getNickname() SPACE nick SPACE channel->getName() SPACE ":is already on channel" RN

// 461
# define ERR_NEEDMOREPARAMS(client, cmd) BASIC_MESSAGE(client, cmd, "Not enough parameters", "461")

// 462
# define ERR_ALREADYREGISTERED(client) SHORT_MESSAGE(client, "You may not register", "462")

// 464
#define ERR_PASSWDMISMATCH(client) \
SEND client, SERVER("464") SPACE client->getNickname() SPACE "Password incorrect" RN

// 471
# define ERR_CHANNELISFULL(client, channel) CHANNEL_MESSAGE(client, channel, "Cannot join channel (+l)", "471")

// 473
# define ERR_INVITEONLYCHAN(client, channel) CHANNEL_MESSAGE(client, channel, "Cannot join channel (+i)", "473")

// 474
# define ERR_BANNEDFROMCHAN(client, channel) CHANNEL_MESSAGE(client, channel, "Cannot join channel (+b)", "474")

// 475
# define ERR_BADCHANNELKEY(client, channel) CHANNEL_MESSAGE(client, channel, "Cannot join channel (+k)", "475")

// 482
# define ERR_CHANOPRIVSNEEDED(client, channel) CHANNEL_MESSAGE(client, channel, "You're not channel operator", "482")


#endif //IRC_NUMERICS_H
