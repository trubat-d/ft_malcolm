#include "ft_malcolm.h"

int get_interface()
{
	
}

int main(int ac, char** av)
{
	printf("Program started\n");
	if(input_check(ac,av))
		return 1;
	struct ifaddrs *ifap, *ifa;
	struct sockaddr_in *sa;
	char *addr;
	getifaddrs(&ifap);
	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family==AF_INET) {
            sa = (struct sockaddr_in *) ifa->ifa_addr;
            addr = inet_ntoa(sa->sin_addr);
            printf("Interface: %s\tAddress: %s\n", ifa->ifa_name, addr);
        }
    }

	freeifaddrs(ifap);
	printf("Program ended\n");
	return 0;
}
