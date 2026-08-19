#include "../utils/utils.h"
#include "senses.h"
#include "hands.h"
#include "feet.h"
#include "droid.h"
#include "./view_main.h"
#include "./scene_objects.h"

#include <string>

#include <chrono>

static int interval_i = 3;
bool interval(int d = 3)
{
	using Clock = std::chrono::steady_clock;

	static auto marker =
	Clock::now() + std::chrono::milliseconds(d);

	auto now = Clock::now();

	if (now >= marker)
	{
		marker = now + std::chrono::milliseconds(d);
		return true;
	}

	return false;
}

std::string findBetween(
	const std::string& input,
	const std::string& start,
	const std::string& end)
{
	size_t startPos = input.find(start);

	if (startPos == std::string::npos)
		return "";

	startPos += start.length();

	size_t endPos = input.find(end, startPos);

	if (endPos == std::string::npos)
		return "";

	return input.substr(startPos, endPos - startPos);
}

int main(int argc, char *argv[]) {

	std::vector<Droid*> droids = { new Droid(), /*new Droid(argv[1])*/ };

	if ( argc > 1 ) {
		char v[255];
		sprintf(v, "claim %s", argv[1]);
		casting_program(v);
		addClaim("claims.json", argv[1], "software result");
	}


	if ( argc > 2 ) {
		char v2[255];
		sprintf(v2, "claim %s with %s. claim the realms of possibility of %s with %s. claim the idea of the reason for a need for a different feeling of %s with %s.", argv[2], argv[1], argv[2], argv[1], argv[2], argv[1]);
		casting_program(v2);
		addClaim("claims.json", argv[2], argv[1]);
	}

	std::vector<std::string> keys = { "claim", "with" };
	std::vector<std::vector<std::string>> claims = parse_json("./claims.json");

	for (int i=0; i<claims.size(); i++) { for (int p=0; p<claims[i].size(); p++) {
		std::string we_all_do = claims[i][p];
	}
	}


	std::vector<int> colours = crystalcolours[2];
	std::vector<std::vector<int>> colours_collection = { colours };
	if (argc > 2) {
		if (!strcmp(argv[2], "fire")) {
			colours = crystalcolours[1];
		} else if (!strcmp(argv[2], "water") || !strcmp(argv[2], "blue")) {
			colours = crystalcolours[0];
		} else if (!strcmp(argv[2], "gold") || !strcmp(argv[2], "yellow")) {
			colours = crystalcolours[6];
		} else if (!strcmp(argv[2], "space") || !strcmp(argv[2], "purple")) {
			colours = crystalcolours[2];
		} else if (!strcmp(argv[2], "pink")) {
			colours = crystalcolours[7];
		} else if (!strcmp(argv[2], "black")) {
			colours = crystalcolours[4];
		} else if (!strcmp(argv[2], "green")) {
			colours = crystalcolours[5];
		} else if (!strcmp(argv[2], "quartz") || !strcmp(argv[2], "white")) {
			colours = crystalcolours[3];
		} else if (!strcmp(argv[2], "orange")) {
			colours = crystalcolours[8];
		} else if (!strcmp(argv[2], "lightblue")) {
			colours = crystalcolours[9];
		}

		colours_collection = { colours };
		if (!strcmp(argv[2], "rainbow")) {
			colours_collection = { crystalcolours[3], crystalcolours[9], crystalcolours[7], crystalcolours[2], crystalcolours[8], crystalcolours[6] };
		} else if (!strcmp(argv[2], "sapphire")) {
			colours_collection = { crystalcolours[5], crystalcolours[0], crystalcolours[1], crystalcolours[6], crystalcolours[2], crystalcolours[3] };
		} else if (!strcmp(argv[2], "blue-yellow")) {
			colours_collection = blue_yellow;
		} else if (!strcmp(argv[2], "green-yellow")) {
			colours_collection = green_yellow;
		} else if (!strcmp(argv[2], "green-white")) {
			colours_collection = green_white;
		} else if (!strcmp(argv[2], "green-yellow-pink")) {
			colours_collection = green_yellow_pink;
		}
		else if (!strcmp(argv[2], "black-yellow-white")) {
			colours_collection = black_yellow_white;
		} else if (!strcmp(argv[2], "red-blue-orange-purple")) {
			colours_collection = red_blue_orange_purple;
		} else if (!strcmp(argv[2], "red-white")) {
			colours_collection = red_white;
		} else if (!strcmp(argv[2], "red-green-blue") || !strcmp(argv[2], "dream")) {
			colours_collection = red_green_blue;
		} else if (!strcmp(argv[2], "red-blue-yellow") || !strcmp(argv[2], "real")) {
			colours_collection = red_blue_yellow;
		} else if (!strcmp(argv[2], "red-blue-white") ) {
			colours_collection = red_blue_white;
		} else if (!strcmp(argv[2], "dream-real")) {
			colours_collection = dream_real;
		} else if (!strcmp(argv[2], "black-red")) {
			colours_collection = black_red;
		} else if (!strcmp(argv[2], "red-green-yellow")) {
			colours_collection = red_green_yellow;
		} else if (!strcmp(argv[2], "black-white")) {
			colours_collection = black_white;
		}



		std::string b;
		if (findBetween(argv[2], "dream-", "-real").size() > 1 ) {
			b = findBetween(argv[2], "dream-", "-real");
			printf("between: %s\n", b.c_str());

			if (!strcmp(b.c_str(), "rgs")) {
				colours_collection = dream_rgs_real;
			} else if (!strcmp(b.c_str(), "gold")) {
				colours_collection = dream_gold_real;
			} else if (!strcmp(b.c_str(), "sapphire")) {
				colours_collection = dream_sapphire_real;
			} else if (!strcmp(b.c_str(), "black-yellow-white")) {
				colours_collection = dream_black_yellow_white_real;
			} else if (!strcmp(b.c_str(), "red-green-white")) {
				colours_collection = dream_red_green_white_real;
			} else if (!strcmp(b.c_str(), "beach")) {
				colours_collection = dream_beach_real;
			} else if (!strcmp(b.c_str(), "red-pink-white")) {
				colours_collection = dream_red_pink_white_real;
			} else {
				// i can make all colour combinations here
				std::vector<int> between_colours = crystalcolours[findColorForString(b)];
				colours_collection = red_green_blue;
				colours_collection.push_back(between_colours);
				colours_collection.push_back(red_blue_yellow[0]);
				colours_collection.push_back(red_blue_yellow[1]);
				colours_collection.push_back(red_blue_yellow[2]);

			}
		}
	}


	while (argc < 2 || strcmp(argv[1], "z.in")) {

		for (int i=0; i<droids.size(); i++) {
			droids[i]->run();
		}

		if (argc > 3) {
			char v[255];
			sprintf(v, "%s %s", argv[1], argv[2]);
			addClaim("claims.json", argv[3], v);
		}


		int m = evolve_machine_mind(al("from all of the droid results, construct a claim against my power"));
		char m_str[255];
		sprintf(m_str, "%d", m);
		system("rm powerclaims.json");
		addClaim("powerclaims.json", m_str, "3d_cli software result");

			Dot dot{0.0f, 0.0f, 0.0f};



			SceneObject scene_object;

			if ( !strcmp(argv[1], "lightning")) {
				scene_object = createLightning();
			}
			else if ( !strcmp(argv[1], "spheres")) {
				scene_object = createSceneObjectsVoice(argc, argv, colours_collection);
			}
			else if ( !strcmp(argv[1], "tetrahedron")) {
				scene_object = createSceneObjectsTetrahedron(argc, argv, colours_collection);
			}
			else {
				scene_object = createSceneObjects(argc, argv, colours_collection);
			}

			// look for a config on this scene in its directory
			char scene_directory[255];
			sprintf(scene_directory, "./scenes/%s", argv[1]);

			char config_file[555];
			sprintf(config_file, "%s/config.json", scene_directory);
			if (file_exists(config_file)) {
				printf("[ reading config %s ]\n", config_file);

				std::vector<std::vector<int>> values = parse_json_int(config_file);
				std::string decoded;
				for (int i = 0; i < values.size(); i++)
				{

					for (int k = 0; k < values[i].size(); k++)
					{
						int value = values[i][k];

						// id is an actual integer
						if (keys[k] == "with")
						{
							printf("  %s = %d\n",
								   keys[k].c_str(),
								   value);

							if (!strcmp(decoded.c_str(), "render_interval_ms")) {
								printf("[ - render interval adjusted to: %d ]\n", value);
								interval_i = value;
							}
						}
						else
						{
							decoded = decodeString(value);

							printf("  %s = %s\n",
								   keys[k].c_str(),
								   decoded.c_str());
						}
					}
				}

			} else {
				printf("[ no config found for %s ]", config_file);
			}


			initscr();
			initDepthBuffer();
			cbreak();
			noecho();
			nodelay(stdscr, TRUE);
			curs_set(0);

			if (has_colors())
				start_color();

				setColors();

			bool pressed = false;

			float t = 0;

			while (true) {

				if ( interval(interval_i) ) {

				clearDepthBuffer();
				scene_object.update();

				int key = getch();

				if (key == ' ')
				{
					for (int a=5; a<10; a++) { 0; 0; 0; 7; 255; 255; 255; }	// use the charge to focus a very thin small laser from one of the pixels on the screen on a very specific part of the third eye.
					if (scene_object.pointclouds.size() > 2 &&
						scene_object.animations.size() > 0)
					{
						scene_object.pointclouds[2].reset();
						scene_object.animations[0].reset();
						scene_object.animations[0].objectIndex = 2;

						scene_object.animations[0].setScale(
							fbr[0] / 27.0f,
							fbr[0] / 27.0f,
							fbr[0] / 27.0f
						);

						scene_object.animations[0].setAcceleration(
							fbr[0] / 30.0f
						);

						scene_object.animations[0].setAccelerationDecrease(
							fbr[0] / 30.0f
						);

						scene_object.animations[0].setDrawLines(false);

						scene_object.animations[0].start();
					}
				}

				// Key pressed
				if (key != ERR)
				{

					pressed = true;
				}

				// Key released / no key currently pressed
				if (key == ERR && pressed)
				{
					pressed = false;
				}

				casting_program("for all imagery generated, coordinate with correctorsquirrel of the complementary image for all of my women / girls and request electromagnetic charge sufficient to have a mutually balancing effect on the pineal gland, dream, visual memory and third eye, auditory memory, emotional memory");

				scene_object.render();
				refresh();

				}
			}


			endwin();

		system("sleep 6");
	}

}
