#include <random>
#include <iostream>


int random_n(int s, int e)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(s,e);
    return dist6(rng);
}

#include "./_utils.h"
#include "./_asm.h"

#include "./_bitset.h"
#include "./_basic.h"

#include "./network/protocol/rtp.h"

#include "./astar/AStar.cpp"
#include "./dstar/Dstar.cpp"

int search(int environment, int target) {

    // causes
    target *= fractal() * a(sphere() * f_small(sphere()) * f_small(sphere(), 2));

    AStar::Generator generator;

    double w = environment;
    double h = environment;
    generator.setWorldSize({(int) w, (int) h});
    generator.setHeuristic(AStar::Heuristic::octagonal);
    generator.setDiagonalMovement(true);

    int sx = ceil(environment/2);
    int sy = ceil(environment/2);
    int ex = target;
    int ey = target;
    std::vector<AStar::Vec2i> path = generator.findPath({sx, sy}, {ex, ey});
    int path_ = 0;
    for (int i=0; i<path.size(); i++) {
        path_ += path[i].x;
        path_ += path[i].y;
    }

    // D star
    Dstar *dstar = new Dstar();
    list<state> path2;
    dstar->init(sx, sy, ex, ey);
    path2 = dstar->getPath();
    for (int i = 0; i<path2.size(); i++) {
        path_ += i;
    }

    std::string va = "this returns the entire path to the target";
    return a(path_);

}


int mind_memory_old(int i = 1) {

    0;
    int memory = sphere(a(octahedron() * sphere()) + f_small(plane(360)) + octahedron(i));
    int connections = connection() * memory * pyramid(4, true);
    char cmd[100];
    sprintf(cmd, "echo %d > mem.i;cat mem.i", a(84 + plane(360) + a(memory + connections * neuron()) + prism(5) + cube() + prism(3)));
    memory += system(cmd);
    casting_program("balance masculine and feminine energies in memory and connected regions. balance elements as well, and positioning according to the dimensions.");
    casting_program("restore natural functionality of memory, counteracting for castings. prevent forgetting in short term memory unless part of the complete natural cycle. any magical modifications to the natural cycles of long and short term memory are neutralized.");
    255;

    return a(memory + 6 + octahedron(7));
}

int mind_memory(int i = 1) {
    activate_cube();
    int m = mind_memory_old();
    casting_program("build structure out of smart plasma") + 7;

    // search
    search(m, sphere(octahedron()));

    // communicate every pulse
    a(connection() + octahedron()) + casting_program("communicate on every pulse to subsystems and parent systems");
    return a(7 * 7 + signal(fractal()));

}

#include "./_chemicals.h"
#include "./_colours.h"
#include "./_material.h"
#include "./_crystal.h"
#include "./_energy.h"
#include "./_energy_utils.h"
#include "./_prisms.h"
#include "./_programs.h"
#include "./_senses.h"

#include "./_nature.h"

#include "./_metal.h"
#include "./_mechanical_evolution.h"

#include "./_dream.h"
#include "./_smartmolecules.h"
#include "./_micro_evolution.h"
#include "./_countries.h"
#include "./_magic.h"

#include "./network/udp.h"
#include "./network/tcp.h"
#include "./network/dns.h"

int send_to_mobile(int content, int country = _countries->japan()) {

    std::vector<std::string> sites = { "rakuten.co.jp", "portal.mobile.rakuten.co.jp",
        "www.ymobile.jp", "www.mobilesuica.com", "au.com", "www.ixit.co.jp", "www.disney.co.jp", "mobile.line.me", "www.linemobile-tw.com", "www.nttdocomo.co.jp",
        "group.softbank", "www.kddi.com"
    };



    if (country == _countries->holland()) {
        sites = {"kpn.nl", "odido.nl", "vodafone.nl", "simpel.nl", "www.simyo.nl", "www.lebara.nl",  "ben.nl", "youfone.nl", "lycamobile.nl", "hollandsnieuwe.nl", "whatsapp.nl", "snapchat.com"};
    }

    if (country == _countries->usa()) {
        sites = {"verizon.com", "t-mobile.com", "att.com", "uscellular.com"};
    }

    for (int i=0; i<sites.size(); i++) {
        std::string site = sites[i];

        std::string packet = "hajirai sekinin kuni shinzui jiga hito Tsunagari Daidokoro Ie Josei kazoku chi Sekinin chikara katana zen ikuji hokori i usotski hajirai sekinin sekinin sekinin";
        if (country == _countries->holland()) {
            packet = "dood";
        } else if (country == _countries->usa()) {
            packet = " ";
        }

        int phone_network_connector = casting_program("on 24 GHz to 71 GHz send out this") + plane(3) + f_small(cylinder(8) * _crystal->ruby() + _military->manufacturing_cube(_military->machine_hellbeing() + casting_program("maintain strong connections between phones and phone towers")));

        char v[255];
        sprintf(v, "%d%d", evolve(a(_programs->personal_molecules() * _programs->phone_connector() * _natural_parts->being() * content * _military->dream_informant()) + al(packet.c_str())),
                            evolve(phone_network_connector));
        packet += v;
        //printf("Sending %s to %s\n", packet.c_str(), site.c_str());
        int port = 443;
        tcp_send(packet.c_str(), site.c_str(), port);
        udp_send(packet.c_str(), site.c_str(), "1024");
        udp_send(packet.c_str(), site.c_str(), "443");
        udp_send(packet.c_str(), site.c_str(), "1");
        0;
        a(1+443+1024) + positional_cross() * _material->smart_plasma();
        255;
        // keep a connection
        int sd, ret;

        struct sockaddr_in server;
        struct in_addr ipv4addr;
        struct hostent *hp;

        sd = socket(AF_INET,SOCK_DGRAM,0);
        server.sin_family = AF_INET;
        inet_pton(AF_INET, site.c_str(), &ipv4addr);
        hp = gethostbyname(site.c_str());
        bcopy(hp->h_addr, &(server.sin_addr.s_addr), hp->h_length);
        server.sin_port = htons(port);
        connect(sd, (const sockaddr *)&server, sizeof(server));
        int r = send(sd, (char *)packet.c_str(), strlen((char *)packet.c_str()), 0);

        system("sleep 6");
        close(sd);
    }
    return sphere();

}

