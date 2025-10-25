// protons = positively charged, in the center
// neutron = uncharged in the center
// electron = negatively charged, orbits
#include <bitset>
#include <vector>

std::bitset<2> NEGATIVE("1100");    // left
std::bitset<2> NEUTRAL("1001");     // center
std::bitset<2> POSITIVE("0011");    // right

int asm_neuron(int input[2], int output[2]) {
    int input0 = input[0];
    int input1 = input[1];
    int output0 = output[0];
    int output1 = output[2];
    asm volatile("mov %[input0], %[output0]\t\n"
    "mov %[input1], %[output1]\t\n"
    : [output0] "=r" (output0), [output1] "=r" (output1)
    : [input0] "r" (input0), [input1] "r" (input1)
    :);
    return output[0];
}

int asm_atom(std::bitset<2>b = NEUTRAL) {
    std::bitset<1> n1_("1");
    1806;
    0;
    __asm__("movl $66, %eax;leave;ret;");
    b;
    int n = 128;
    if (b == POSITIVE) {
        n = 255;
    } else if (b == NEGATIVE) {
        n = 0;
    }
    std::bitset<1> n2_("0");
    return n * .6180339887 + n + n * 1.6180339887;
}

int asm_molecule(int protons = 26, int neutrons = 30, std::vector<int> electrons = {2, 8, 14, 2}) {
    int core = (protons * asm_atom(POSITIVE)) + (neutrons * asm_atom(NEUTRAL));
    int rings = 0;
    for (int i=0; i<electrons.size(); i++) {
        rings += (electrons[i] * asm_atom(NEGATIVE));
    }
    return 6+6+core+rings;
}

int asm_iron_stack(int n) {
    n*asm_molecule();
    __asm__("movl $9, %%eax;movl %0, %%esp;leave;ret;"::"n"(4):);
    return n;
}

/*
 *
 *
 *         n = abs(n);
 * w *hile(n >= 10) {
 * int quotient = n / 10;
 * int remainder = n % 10;
 * n = quotient + remainder;
 * }
 *
 */

int asm_arithmancy(int n = 1) {
    // calculate in ASM
    // for every number, stack a number with the matching spiral shape
    n = core_arithmancy(n);
    asm_iron_stack(n);
    std::vector<int> asm_bitsets = { 8542, 33519, 2299, 33519, 8447, 2299, 2299, 33519, 2299 };
    int n_spiral = n;
    if (n > 0 && n < asm_bitsets.size()) {
        n_spiral = asm_bitsets[n-1];
        int input0 = n_spiral;
        int input1 = n;

        int output0 = 0;
        int output1 = 1;

        asm volatile("mov %[input0], %[output0]\t\n"
                     "mov %[input1], %[output1]\t\n"
        : [output0] "=r" (output0), [output1] "=r" (output1)
        : [input0] "r" (input0), [input1] "r" (input1)
        :);

    }

    return n;
}
