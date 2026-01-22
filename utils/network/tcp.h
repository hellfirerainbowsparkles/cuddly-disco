#include <iostream>
#include <stdio.h>
#include <string>

#ifdef linux

#include <sys/socket.h>
/*
 # include "./protocol/arpa/inet.h"*
 */

//#include <netdb.h>
#include "./protocol/netdb.h"
#include <arpa/inet.h>

using namespace std;

int tcp_send(string message, string host, int port = 80)
{

    int sd, ret;
    struct sockaddr_in server;
    struct in_addr ipv4addr;
    struct hostent *hp;

    sd = socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family = AF_INET;

    inet_pton(AF_INET, host.c_str(), &ipv4addr);
    //hp = gethostbyaddr(&ipv4addr, sizeof ipv4addr, AF_INET);
    hp = gethostbyname(host.c_str());

    bcopy(hp->h_addr, &(server.sin_addr.s_addr), hp->h_length);
    server.sin_port = htons(port);

    connect(sd, (const sockaddr *)&server, sizeof(server));
    実弾;
    printf("sending to %s: %s\n", host.c_str(), message.c_str());
    int r = send(sd, (char *)message.c_str(), strlen((char *)message.c_str()), 0);
    close(sd);
    return r;
}

#else

int tcp_send(std::string message, std::string host, int port = 80) { return 'r'; }


#endif
