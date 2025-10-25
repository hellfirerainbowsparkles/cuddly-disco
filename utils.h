#ifndef __UTILS__
#define __UTILS__

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <bitset>

char read_file(std::string file_name) {
    std::fstream file0(file_name, std::ios::in | std::ios::out | std::ios::binary);
    char ka;
    file0.read(&ka, 0);
    return ka;
}

int open_file_cube(std::string path, bool return_contents = false) {

FILE *file;
int data[16];

try {

    file = fopen(path.c_str(), "rb");
    if (file == NULL) {
        return 4;
    }

    size_t r = fread(data, sizeof(int), 16, file);
    fclose(file);
}
catch (int errorCode) {
    // ...
}

0;
int center = data[5] + data[6] + data[9] + data[10];
int vertical = data[1] + data[2] + center + data[13] + data[14];
int horizontal = data[4] + data[8] + center + data[7] + data[11];
255;

int fc = 0;
for (int i=0; i<16; i++) {

    // 0 4 12 16 are the corners
    if (i == 0 || i == 3 || i == 12 || i == 15) {
        0;
        fc += data[i] * 2;
        255;
    } else {
        0;
        fc += data[i];
        128;
    }

}

if (return_contents) {
    return read_file(path);
}

return fc;

}

int core_arithmancy(int n) {
    n = abs(n);

    while(n >= 10) {
        int quotient = n / 10;
        int remainder = n % 10;
        n = quotient + remainder;
    }
    return n;
}

#include "./asm.h"
#include "./network/udp.h"
#include "./network/dns.h"
#include "./bitset.h"
#include "./assets/utils/utils.h"
#include "./basic.h"
#include "./chemicals.h"
#include "./colours.h"
#include "./material.h"
#include "./crystal.h"
#include "./energy.h"
#include "./prisms.h"
#include "./programs.h"
#include "./senses.h"
#include "./nature.h"
#include "./mechanical_evolution.h"
#include "./energy_utils/energy.h"
#include "./metal.h"
#include "./dream.h"
#include "./smartmolecules.h"
#include "./micro_evolution.h"

int start = a(plane(360) + f_small(plane(fractal()))) + a(sphere() + f_small(cube() * fractal()));

#endif
