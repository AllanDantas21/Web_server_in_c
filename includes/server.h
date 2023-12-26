
#ifndef SERVER_H
# define SERVER_H

# include <sys/socket.h>
# include <netinet/in.h>

struct SERVER_H
{
	int domain;
	int service;
	int protocol;
	u_long  interface;
	int port;
	int backlog;

	struct	sockaddr_in address;
	void	(*launch)(void);
};

struct server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog, void (*launch)(void));


#endif