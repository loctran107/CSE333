#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>

#define SIZE 1024
int main(int argc, char** argv) {
	
	char response_data[SIZE];

	//Open the html file
	FILE* html_data = fopen("index.html", "r");
	
	//read the html file put it in reponse_data
	fgets(response_data, SIZE, html_data);

	//Status code to let the client know whether the resouces 
	//they requested was approved
	char http_header[SIZE * 2] = "HTTP/1.1 200 OK\r\n\n";
	
	//Combine the header and response data to send back to client
	strcat(http_header, response_data);

	//create a socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	// define the address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8001);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	//bind our socket into our connection
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	
	//Listen to the socket
	listen(server_socket, 5);
	
	int client_socket;
	while (1) {
		client_socket = accept(server_socket, NULL, NULL);
		send(client_socket, http_header, sizeof(http_header), 0);
		//close(client_socket);
	}

	

	return EXIT_SUCCESS;
}
