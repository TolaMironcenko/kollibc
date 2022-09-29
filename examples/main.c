#include <stdio.h>
#include "../src/in.h"
#include <sys/socket.h>

int main()
{
	struct sockaddr_in server_addr;

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(9090);
	inet_aton("127.0.0.3", &server_addr.sin_addr);

	char inet_addr_to_terminal[sizeof(server_addr.sin_addr)];

	inet_ntop(AF_INET, &(server_addr.sin_addr), inet_addr_to_terminal, sizeof(server_addr));

	printf("sin_family = %d\nsin_port = %d\nsin_addr = %s\n",
           server_addr.sin_family,
           htons(server_addr.sin_port),
           inet_addr_to_terminal);

	printf("sin_familyd = %d\nsin_port_uns_short = %d\nsin_addrd = %ld\n",
           server_addr.sin_family,
           server_addr.sin_port,
           server_addr.sin_addr.s_addr);

	return 0;
}