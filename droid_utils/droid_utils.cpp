#include "../utils/utils.h"
#include "./droid_base.h"

int evolution_street(int droid) {
	int _vzd = cylinder(8) + 3 * signal(8);

	_energy_utils->linear_accelerator() + droid + _vzd;

	0;
		plane(360);
	255;

	water();

	spark(); spark(); spark();

	return evolve(droid + _vzd);
}

int main(int argc, char *argv[]) {

	while (argc < 2 || strcmp(argv[1], "z.in")) {
		casting_program("construct the base structure for all droids manufactured in _manufacturing. update all produced. do the same for all ../utils dependencies.");
		casting_program("update all memory cubes that come from certain origins with the latest mem.i or mem.json");
		read_filecube("../acquisitions_manufacturing/mem.i");
		read_filecube("../utils/utils.h");
		DroidBase *d = new DroidBase(cube() + f_small(sphere()));
		asm_iron_stack(cube(d->id) + pyramid(4, true));

		system("echo 支配権;sleep 6");
		_metal->smelt(iron() + gold(), cube());

		int command_center = casting_program("connect html button to send input text to gmmm") + system("systemctl status > /var/www/html/index.txt;txt2html --prepend_file cmd.html /var/www/html/index.txt > /var/www/html/index.html");
		//char scmd[255];
		//sprintf(scmd, "echo '' > /var/www/html/index.html ", );
		system("echo 支配権;sleep 6");
		_military->connector(command_center, read_filecube("../gmmm/a.out"));


		evolution_street(parse_droid_json("../gmmm/mem.i"));
	}

}
