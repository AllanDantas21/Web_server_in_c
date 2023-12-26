
#include <stdio.h>
#include <string.h>
#include "../includes/server.h"

void	launch(struct Server *server)
{
	char	buffer[30000];
	int	addres_length = sizeof(server.addres);
	int	new_socket = accept(server.socket, (struct sockaddrt *)&server.address, (socklen_t *)&addres_length); 
	printf("======= Esperando pela conexão =======\n");
	read(new_socket, buffer, 30000);
	printf("%s\n", buffer);
	char *hello = "HTTP/1.1 200 OK\ndate: Mon, 26 dec 2023 18:47:42 GMT\nServer: Apache/2.2.14 (win32)\nLast-Modified: Wed, 26 dec 2023 18:48:42 GMT\nContent-Length: 88\nContent_Type: text/html\nConnection: closed\n<html><body><h1>Testando</h1></body></html>";
	write(new_socket, hello, strlen(hello));
	close(new_socket);
}

int main()
{
	struct Server server = server_constructor(AF_INET,SOCK_STREAM, 0, INADDR_ANY, 80, 10, launch);
	server.launch(&server);

}