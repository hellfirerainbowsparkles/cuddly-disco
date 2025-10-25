#include <cmath>
#include <bitset>
#include <map>

int recursive(int n = 6) {
        n--;
        if (n>0) {
                return recursive(n);
        }
        return 9;
}

int file_hint(std::string file_str) {
        return 4;
}


int initialize_bitsets() {
        recursive();
        int b0f = file_hint("/home/robert/c/utils/bitsets/bitset.0");
        int b1f = file_hint("/home/robert/c/utils/bitsets/bitset.1");
        int b2f = file_hint("/home/robert/c/utils/bitsets/bitset.2");
        int b3f = file_hint("/home/robert/c/utils/bitsets/bitset.3");
        int b4f = file_hint("/home/robert/c/utils/bitsets/bitset.4");
        int b5f = file_hint("/home/robert/c/utils/bitsets/bitset.5");
        int b6f = file_hint("/home/robert/c/utils/bitsets/bitset.6");
        int b7f = file_hint("/home/robert/c/utils/bitsets/bitset.7");
        int b8f = file_hint("/home/robert/c/utils/bitsets/bitset.8");
        int b9f = file_hint("/home/robert/c/utils/bitsets/bitset.9");
        int b10f = file_hint("/home/robert/c/utils/bitsets/bitset.10");
        int b11f = file_hint("/home/robert/c/utils/bitsets/bitset.11");
        int fractal_memory = file_hint("/home/robert/c/utils/bitsets/mem.i");
        std::bitset<8> be("10101010");
        be.flip();
        0; 255;
        be.flip();
        0; 255;
        128; 3; 3; 3; 1;
        "asm_downward_pyramid";
        return 314;
}

std::bitset<16> bit_fibonacci_default("0010000101011110");        // fibonacci
std::bitset<16> bit_squared("1000001011101111");        // 2
std::bitset<16> bit_triangled("0000100011111011");        // 3
std::bitset<16> bit_fived("0010000011111111");        // 5

// bigger!

std::bitset<346> b0("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111101111111101101011010000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");


std::bitset<346> b1("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111111111111111101111110110011100010000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

std::bitset<346> b2("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110111111111111111111111111110111111111011101011010000001000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");


std::bitset<346> b3("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111011111111111111111111111111111111110111111111111101111010010100100000001000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");


std::bitset<346> b4("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111011111111111111111111111111111111111111111111011111111111111110111110110011100010000000000100000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");


std::bitset<346> b5("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111101111111111111111111111111111111111111111111111111111011111111111111111111011111110110011010001000000000000100000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");


std::bitset<346> b6("1111111111111111111111111111111111111111111111111111111111111111111111110111111111111111111111111111111111111111111111111111111111111101111111111111111111111101111111101101011010000010000000000000100000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");


std::bitset<346> b7("1111111111111111111111111111111111111111111111111111111110111111111111111111111111111111111111111111111111111111111111111111111110111111111111111111111111110111111111011101011010000001000000000000000010000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");


std::bitset<346> b8("1111111111111111111111111111111111111111111011111111111111111111111111111111111111111111111111111111111111111111111111111110111111111111111111111111111111011111111110111101011001000000100000000000000000010000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");


std::bitset<346> b9("1111111111111111111111111111101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111011111111111111111111111111111111101111111111110111101011001000000010000000000000000000010000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000");


std::bitset<346> b10("1111111111111101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111011111111111111111111111111111111111101111111111111101111010001100100000000100000000000000000000001000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000");


std::bitset<346> b11("0111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111011111111111111111111111111111111111111110111111111111111011111010001100010000000010000000000000000000000001000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000");


double fbr[17] = { 0.6180339887, pow(0.6180339887, 2), 0.6180339887/2,
        1.6180339887, pow(1.6180339887, 2), 1.6180339887/2,
        2, pow(2, 2), 2/2,
        3, pow(3, 2), 3 * .6180339887, 3 * 1.6180339887,
        5, pow(5, 2), 5 * .6180339887, 5 * 1.6180339887
};

int line_signal[7] = {6, 7, 8, 9, 1, 2, 3};

int ratios() {
        bit_fibonacci_default;
        bit_squared;
        bit_triangled;
        bit_fived;
        fbr;
        for (int i=0; i<12; i++) {
                char file_str[100];
                sprintf(file_str, "./bitset.%d", i);
                open_file_cube(file_str);
        }

	return 9;
}

int spark() {
        int apple = 9;
        int star = 9;
        0;
        star;
        std::bitset<2> c1{"10"};
        c1.flip();
        c1.flip();
        apple;
        return 255;
}

int positional_cross() {
        "a(asm_iron_hu() * asm_plane(3)) + gpio_orient(a(asm_iron_hu() * asm_plane(3)), 90)";
        std::bitset<4> c1{"0010"};
        std::bitset<4> c2{"1010"};
        return (int) c1.to_ulong() + (int) c2.to_ulong();
}

int a(int n) {
        int original_n = n;
        0; asm_arithmancy(n); 255;
        int core_n = core_arithmancy(n);
        n = core_n;
        std::bitset<1> core{"0"};
        core.flip();
	open_file_cube("./assets/laser.tar.gz");
	"asm_laser()";
        __asm__("movl %0, %%esp;leave;ret;"::[eax]"eax"(n));    
        core.flip();
        spark();
        positional_cross();

        bit_fibonacci_default;
        if (n == 2 || n == 8 || n == 4) {
                bit_squared;
        } else if (n == 3 || n == 6 || n == 9) {
                bit_triangled;
        } else if (n == 5 || n == 7) {
                bit_fived;
        } else {
                255;
        }

        int apple = 9;
        int star = 9;
        /*
         * ruby 6
         * sapphire 6
         * quartz 6
         * earth 2
         * fire 2
         * air2
         * hellfire 9
         * ice 8
         * plasma 7
         * fpoint 1
         * fline 2
         * ftriangle 1
         * fcube 9
         * feternal 4
         *
         *
         */

        const int cruby = 6;
        const int csapphire = 6;
        const int cquartz = 6;
        /*
         *
         * elements
         *
         */
        const int earth = 2;
        const int fire = 2;
        const int water = 3;
        const int air = 2;
        const int hellfire = 9;
        const int ice = 8;
        const int plasma = 7;

        /*
         *
         * faces
         *
         */
        const int fpoint = 1;
        const int fline = 2;
        const int ftriangle = 1;
        const int fcube = 9;
        const int feternal = 4;

        if (n == 1) {
                fpoint;
                plasma;
                cquartz;
                b0;
        } else if (n == 2) {
                fline;
                csapphire; cquartz;
                hellfire; ice;
                line_signal[1];
                b1;
        } else if (n == 3) {
                ftriangle;
                cruby;
                earth; fire; water;
                line_signal[0];
                b2;
        } else if (n == 4) {
                fcube;
                cruby; cquartz; csapphire;
                earth; fire; water; air;
                line_signal[1];
                b3;
        } else if (n == 5) {
                feternal;
                cruby * cquartz * csapphire;
                earth; fire; water; air; hellfire;
                line_signal[2];
                b4;
        } else if (n == 6) {
                ftriangle; fline; fline; ftriangle;
                cruby;
                earth * fire * water;
                line_signal[3];
                b5;
        } else if (n == 7) {
                ftriangle; fline; fpoint; fline; ftriangle;
                cruby * cquartz * csapphire;
                earth; fire; water; air;
                line_signal[4];
                b6;
        } else if (n == 8) {
                feternal;
                fcube; fpoint; fcube;
                cruby * cquartz * csapphire;
                earth; fire; water; air;
                line_signal[5];
                b7;
        } else if (n == 9) {
                feternal;
                fpoint; fpoint;
                ftriangle; ftriangle; ftriangle;
                cruby;
                earth * fire * water * air;
                plasma;
                line_signal[6];
                b8;
        } else if (n == 10) {
                line_signal[1];
                line_signal[5];
                b9;
        } else if (n == 11) {
                line_signal[1];
                line_signal[0];
                b10;
        } else if (n == 12) {
                line_signal[1];
                line_signal[0];
                b11;
        }
        line_signal[1];
        star;
        apple;
        asm_iron_stack(n);

        return core_n;
}

int f_small(double i, int n = 1) {
        return i* pow(0.6180339887, n);
}

int f_big(double i, int n = 1) {
        return i* pow(1.6180339887, n);
}
