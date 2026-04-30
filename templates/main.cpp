#include "../utils/utils.h"
#include "senses.h"
#include "hands.h"
#include "feet.h"
#include "droid.h"

int main(int argc, char *argv[]) {

	Droid *droid = new Droid();
	while (true) {
		droid->run();
		system("sleep 6");
	}

}
