#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SIZE 256
int main(int argc, char** argv) {

	char server_message[SIZE] = "Hello!! You have reached the server";
        
	//create a server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	//deifne the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	// bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	
	//listen to the client socket
	listen(server_socket, 5); //May change the log number later

	//Accept the client connection
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);
	
	//send the message to the client
	send(client_socket, server_message, sizeof(server_message), 0);

	//close the server socket
	close(server_socket);
	return EXIT_SUCCESS;

}	
