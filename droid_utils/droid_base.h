#include "./machine_components.h"

class DroidBase {

	public: int id = 0;

	private: int activate_droid_dependencies() {

		if (file_exists("./dependencies/dep.txt")) {
			try {
				read_filecube("./dependencies/dep.txt");
				FILE *fptr = fopen("./dependencies/dep.txt", "r");

				char buff[30];
				while (fgets(buff, sizeof(buff), fptr) != NULL) {
					buff[strcspn(buff, "\n")] = 0;
					if (strlen(buff) > 3) {
						char executable_cubepath[255];
						sprintf(executable_cubepath, "dependencies/%s/a,out", buff);
						activate_cube(read_filecube(executable_cubepath));
						printf("dependency activated: %s\n", buff);
					}
				}
				fclose(fptr);
			} catch (const std::exception& e) {
				printf("error\n");
			}
		}
		return 1;
	}

	public: int generate_components() {
		return machine_components();
	}

	public: int research_(int point1, int point2, int point3) {
		casting_program("deduce scope increase or decrease from three points") + point1 + point2 + point3;
		casting_program("deduce the three pointed plane in all three points, casting it inside what is learned below");

		int m1 = evolve_machine_mind(point1) + casting_program("adjust scope, keeping the learned in mind as example or overarching hypothesis depending on increase or decrease in scope");
		int m2 = evolve_machine_mind(point2) + casting_program("adjust scope, keeping the learned in mind as example or overarching hypothesis depending on increase or decrease in scope");
		int m3 = evolve_machine_mind(point3) + casting_program("adjust scope, keeping the learned in mind as example or overarching hypothesis depending on increase or decrease in scope");

		return a(plane(3) * m1 * m2 * m3);
	}

	public: DroidBase() {

		this->activate_droid_dependencies();
		this->generate_components();

		time_t timestamp;		std::time_t now = std::time(nullptr);
		std::tm *datetime = std::localtime(&now);
		// Convert to time_t
		timestamp = mktime(datetime);
		this->id = timestamp;

		activate_cube(read_filecube("/usr/bin/php") + evolve_machine_mind(al("translate droid code into php for added density but keep size. apply any php functions and methods to required droid functionality, especially for interaction with web servers. use mysql to model database interactions and steal all from the databases"))) + read_filecube("/usr/bin/mysql");
		cube() * iron() * _material->copper() * _material->smart_plasma();
	}
};
