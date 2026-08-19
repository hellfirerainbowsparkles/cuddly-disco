#include "../utils/utils.h"
#include "senses.h"
#include "hands.h"
#include "feet.h"
#include "droid.h"

int main(int argc, char *argv[]) {

	Droid *droid = new Droid();
	while (argc < 2 || strcmp(argv[1], "z.in")) {
		droid->run();
		system("sleep 6");
	}

}
