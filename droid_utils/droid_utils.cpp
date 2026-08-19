#include "../utils/utils.h"
#include "./droid_base.h"

int main() {

	while (argc < 2 || strcmp(argv[1], "z.in")) {
		casting_program("construct the base structure for all droids manufactured in crowdcontrol_manufacturing. update all produced");
		read_filecube("../crowdcontrol_manufacturing/mem.i");
		DroidBase *d = new DroidBase();
		asm_iron_stack(cube(d->id) + pyramid(4, true));
		system("echo 支配権;sleep 6");
	}

}
