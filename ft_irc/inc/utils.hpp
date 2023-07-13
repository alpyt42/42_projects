#ifndef UTILS_HPP
# define UTILS_HPP

// LIBRAIRIES
# include <string>
# include <sys/socket.h>
# include <sys/ioctl.h>
# include <sys/ioctl.h>
# include <iostream>
# include <algorithm>
# include <netinet/in.h>
# include <stdio.h>
# include <cstdlib>
# include <cstring>
# include <signal.h>
# include <sys/poll.h>
# include <unistd.h>
# include <fcntl.h>
# include <vector>
# include <map>
# include <poll.h>
# include <sstream>
# include <arpa/inet.h>
# include <ctime>
# include <functional>
# include <csignal>
#include <cerrno>
# include <cctype> // Pour les fonctions de manipulation de caractères


// STANDARD COLORS
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// BRIGHT COLORS
#define BBLACK  "\033[90m"
#define BRED    "\033[91m"
#define BGREEN  "\033[92m"
#define BYELLOW "\033[93m"
#define BBLUE   "\033[94m"
#define BMAGENTA "\033[95m"
#define BCYAN   "\033[96m"
#define BWHITE  "\033[97m"

#define NC       "\033[0m"

#endif