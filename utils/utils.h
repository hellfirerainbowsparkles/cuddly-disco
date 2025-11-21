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
#include "./network/udp.h"
#include "./network/dns.h"
#include "./_bitset.h"
#include "./_basic.h"
#include "./_chemicals.h"
#include "./_colours.h"
#include "./_material.h"
#include "./_crystal.h"
#include "./_energy.h"
#include "./_prisms.h"
#include "./_programs.h"
#include "./_senses.h"
#include "./_nature.h"
#include "./_mechanical_evolution.h"
#include "./_energy_utils.h"
#include "./_metal.h"
#include "./_dream.h"
#include "./_smartmolecules.h"
#include "./_micro_evolution.h"
#include "./astar/AStar.cpp"
#include "./dstar/Dstar.cpp"

