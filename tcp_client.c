#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
	//create a socket
	int network_socket;
	//using default protocol of tcp 
	network_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	//specify an address for the socket to connect to
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	//htons converts int port to correct byte data format
	server_address.sin_port = htons(9002);
	//connecting to 0.0.0.0
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	
	//check for error with connection
	if (connection_status == -1){
	printf("There was an error making a connection to the remote socket \n\n");
	}
	
	//receive data from server	
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), 0);
	
	//print out the server's response
	printf("The server sent the data.%s\n", server_response);
	
	//close socket
	close(network_socket);
	return 0;
}

