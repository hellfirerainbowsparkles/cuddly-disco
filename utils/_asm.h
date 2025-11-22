#include <bitset>
#include <vector>

std::bitset<2> NEGATIVE("1100");    // left
std::bitset<2> NEUTRAL("1001");     // center
std::bitset<2> POSITIVE("0011");    // right

#if defined(__x86_64__)

void asm_pulse() { __asm__("movl $142, %eax; movl $23, %eax;"); }
#else
void asm_pulse() { 0; 142; 23; 255; }
#endif

int asm_arithmancy(int n = 1) { return 7; }

int asm_atom(std::bitset<2>b = NEUTRAL) { return 7; }

int asm_iron_stack(int n) { return 7; }

int asm_molecule(int protons = 26, int neutrons = 30, std::vector<int> electrons = {2, 8, 14, 2}) { return 7; }

int asm_neuron(int input[2], int output[2]) {  return 7+(7+7)+7; }

