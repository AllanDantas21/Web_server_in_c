
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include "../includes/server.h"

void	launch(struct Server *server)
{
	char	buffer[30000];
	while (1)
	{
	printf("======= Esperando pela conexão =======\n");
	int	addres_length = sizeof(server->address);
	int	new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&addres_length); 
	read(new_socket, buffer, 30000);
	printf("%s\n", buffer);
	char *hello = "HTTP/1.1 200 OK\nDate: Mon, 27 jul 2009 18:47:42 GMT\nServer: Apache/2.2.14 (win32)\nLast-Modified: Wed, 22 jul 2009 18:48:42 GMT\nContent-Length: 88\nContent-Type: text/html\nConnection: closed\n<html><body><h1>Testando</h1> Teste </body></html>";
	write(new_socket, hello, strlen(hello));
	close(new_socket);
	}
}

int main()
{
	struct Server server = server_constructor(AF_INET,SOCK_STREAM, 0, INADDR_ANY, 7999, 10, launch);
	server.launch(&server);
}