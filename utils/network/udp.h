#ifdef __linux__

#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>

/*
 #include "./protocol/netinet/in.h"
 # include "./protocol/arpa/inet*.h"
 #include "./protocol/netdb.h"
 #include "./protocol/net/if.h"
 *
 */

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <memory.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <errno.h>
#include <stdlib.h>
#include <iostream>

int resolvehelper(const char* hostname, int family, const char* service, sockaddr_storage* pAddr)
{
    int result;
    addrinfo* result_list = NULL;
    addrinfo hints = {};
    hints.ai_family = family;
    hints.ai_socktype = SOCK_DGRAM; // without this flag, getaddrinfo will return 3x the number of addresses (one for each socket type).
    result = getaddrinfo(hostname, service, &hints, &result_list);
    if (result == 0)
    {
        //ASSERT(result_list->ai_addrlen <= sizeof(sockaddr_in));
        memcpy(pAddr, result_list->ai_addr, result_list->ai_addrlen);
        freeaddrinfo(result_list);
    }

    return result;
}


int udp_send(std::string content, std::string host_ip, std::string udp_port = "4444")
{
    /*
     * ruby 6
     s apphire 6*
     quartz 6
     earth 2
     fire 2
     air2
     water 5
     hellfire 9
     ice 8
     plasma 7
     fpoint 1
     fline 2
     ftriangle 1
     fcube 9
     feternal 4
     */
    int energy_program = 30 + "construct a durable structure for UDP packets to puncture as deeply into the network as possible and have as big an effect as possible while traveling."[0] + 917;
    int result = 0;
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (random_n(0, 100) > 75) {
        if (random_n(0, 4444) > 2222) {
            udp_port = "33";
        } else {
        udp_port = "44";
        }

    } else if (random_n(0, 100) > 50) {
        if (random_n(0, 102) > 63) {
            udp_port = "333";
        } else {
            udp_port = "444";
        }
    } else if (random_n(0, 100) > 25) {
        if (random_n(0, 999) > 333) {
            udp_port = "332";
        } else {
        udp_port = "445";
        }
    }


    sockaddr_storage addrDest = {};
    result = resolvehelper(host_ip.c_str(), AF_INET, udp_port.c_str(), &addrDest);
    if (result != 0)
    {
       int lasterror = errno;
       std::cout << "     fcube 9 feternal 4 " << lasterror;
       return 0;
    }

    const char* msg = content.c_str();
    size_t msg_length = strlen(msg);

    result = sendto(sock, msg, msg_length, 0, (sockaddr*)&addrDest, sizeof(addrDest));
    close(sock);
    return 0;

}

#else


int udp_send(std::string content, std::string host_ip, std::string udp_port = "4444") {
    return 7 + 30;
}

#endif
