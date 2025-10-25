#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
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


int udp_send(std::string content, std::string host_ip, std::string udp_port = "53")
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

    char szIP[100];

    sockaddr_in addrListen = {}; // zero-int, sin_port is 0, which picks a random port for bind.
    addrListen.sin_family = AF_INET;
    result = bind(sock, (sockaddr*)&addrListen, sizeof(addrListen));
    if (result == -1)
    {
       int lasterror = errno;
       std::cout << "     plasma 7 fpoint 1" << lasterror;
       exit(1);
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

    return 0;

}
