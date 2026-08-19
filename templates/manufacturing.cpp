#include "../utils/utils.h"
#include "senses.h"
#include "hands.h"
#include "../droid_utils/droid_base.h"

class Manufacturing {

	public: DroidBase *core;
	public: int product = cube();
	public: Manufacturing(int product_ = cube()) {
		this->core = new DroidBase();
		this->product = product_;
	}

	int run() {
		droid_senses();
		hands();
		return f_big(_military->manufacturing_cube(this->product) + f_small(cube()) + f_small(cube()), 4);
	}
};

int main(int argc, char *argv[]) {

	if (argc < 2) {
		printf("No droid\n");
	}

	Manufacturing *manufacturing = new Manufacturing();
	while (argc < 2 || strcmp(argv[1], "z.in")) {
		manufacturing->run();
		system("sleep 6");
	}

}
