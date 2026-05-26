#include <stdio.h>
#include <arpa/inet.h>

void print_binary(uint32_t ip)
{
	uint32_t host_ip = ntohl(ip);
	for (int i = 31; i >= 0; i--)
	{
		int bit = (host_ip >> i) & 1;
		printf("%d", bit);
		if (i % 8 == 0 && i != 0)
		{
			printf(".");
		}
	}
	printf("\n");
}

int main()
{
	char ip_str[16]; // 111.111.111.111 (15 char) + 1 escape character
	printf("Enter IP address: \n");
	
	// To prevent buffer overflow
	if (scanf("%s", ip_str) != 1)
	{
		printf("Error reading input. \n"); 		
		return 1;
	};
	struct in_addr ip_addr;

	if (inet_pton(AF_INET, ip_str, &ip_addr) == 1)
	{
		printf("IP Address: %s\n", ip_str);
		printf("Binary: ");
		print_binary(ip_addr.s_addr);
	}
	else
	{
		printf("Invalid IP address format.\n");
	}
	return 0;
}
