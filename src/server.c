#include "../includes/server.h"

struct	Server server_constructor(int domain, int service, int protocol,
 u_long interface, int port, int backlog, void (*launch)(void))
{
	struct Server server;
}