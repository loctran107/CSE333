#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#define SIZE 256
int main(int argc, char** argv) {
	
	int socketfd;
	
	//create a socket
	socketfd = socket(AF_INET, SOCK_STREAM, 0); //0 means default protocol TCP
	
	//Specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET; //specify the type of family address we're connecting to
	server_address.sin_port = htons(9002); //convert a given port number to number the struct can understand
	//May add an IP address in this line (optional)
	server_address.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(socketfd, (struct sockaddr *) &server_address, sizeof(server_address));
	if (connection_status == -1) {
		perror("Connection with socket failed");
		exit(EXIT_FAILURE);
	}
	
	//receive data from the server
	char server_response[SIZE];
	recv(socketfd, &server_response, sizeof(server_response), 0); //Optional flag of 0
	
	// print out the data from the receiving end
	printf("The message we got back is: %s\n", server_response);

	//Close the socket
	close(socketfd);
	
	return EXIT_SUCCESS;
}	
