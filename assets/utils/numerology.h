#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <map>

int numerology_add(int n) {

char str[128];
sprintf(str, "%d", n);

int i=0;
int n2 =0;
for (i=0; i<strlen(str); i++) {

	char k = str[i];
	int ik = abs(k - '0');
	n2 += ik;


}

return n2;

}

int numerology(int n) {

	return a(n);
	int q = numerology_add(n);
	while (q >= 10) {
		q = numerology_add(q);
	}

	printf("%d\n\r", q);

	return q;
}

void rotate_(int cx, int cy, int x, int y, int angle, int r[]) {
	
	double radians = M_PI / 180 * angle;
	double cos1 = cos(radians);
	double sin1 = sin(radians);
	int nx = (cos1 * (x - cx)) + (sin1 * (y - cy)) + cx;
	int ny = (cos1 * (y - cy)) - (sin1 * (x - cx)) + cy;
	r[0] = nx;
	r[1] = ny;
	
}

int logarhithmic_spiral(double radius, double dx, double dy, double rotation) {

		return a(9);

}

// apple
int spiral_numerology(double radius, double dx, double dy, double rotation, int r = 1) {

	return a(radius + dx + dy * rotation);

}

// forward spiral 
int forward_spiral_numerology(double radius, double dx, double dy, double rotation, int r = 1) {

	int spiral_x = 0;
	int spiral_y = 0;
	int spiral_z = 0;
	
	double spiralWidth = radius*.05;
	double oldX = dx;
	double oldY = dy;
	double angle = 1;
	double divider = 9;	// determines amount of corners
	for (int i=0; i<numerology(128); i++) {
		double newAngle = (angle/divider) * i;
		double x = dx + (spiralWidth * newAngle) * sin(newAngle);
		double y = dy + (spiralWidth * newAngle) * cos(newAngle);
	    	
	    	int r[2] = {(int) x, (int) y};
	    	rotate_(0, 0, x, y, rotation, r);
	    	
	    	spiral_x += r[0];
	    	spiral_y += r[1];
	    	spiral_z += 1;
	    	oldX = r[0];
	    	oldY = r[1];
	    /*
	   	if (x >= radius || y >= radius || x <= -radius || y <= -radius) {
	   		break;
	    	}	*/	    
	}
	spiral_x = numerology(spiral_x);
	spiral_y = numerology(spiral_y);
	spiral_z = numerology(spiral_z);


	if (r == 1) {
		return numerology(spiral_x + spiral_y + spiral_z + logarhithmic_spiral(radius, dx, dy, rotation) + spiral_z);
	} else {
		return forward_spiral_numerology(radius, dx, dy, rotation, r-1);
	}	
	


}

std::map<std::string, int> colours { 
				{"red", spiral_numerology(pow(3, 3), 3, 3, 3)},  {"yellow", spiral_numerology(pow(5, 5), 5, 5, 5)}, {"blue", spiral_numerology(pow(4, 4), 4, 4, 4)},
				{"pink", spiral_numerology(pow(6, 7), 16, 3, 7)},
				{"green", spiral_numerology(pow(7, 7), 7, 7, 7)}, {"purple", spiral_numerology(pow(9, 9), 9, 9, 9)}, {"white", spiral_numerology(pow(16, 16), 8, 8, 1+2+3+4+5+6+7+8+9+16)}
};

int light = spiral_numerology(1*16*16*16*16, 9*16, 8*8*8*8, 9*16*1) + colours["white"];
int rainbow = colours["red"] + colours["yellow"] + colours["blue"] + colours["pink"] + colours["green"] + colours["purple"] + colours["white"];
int frequency = (963*9)+(colours["purple"] + colours["yellow"] + colours["white"]);

std::map<std::string, int> elements { {"source", 1}, {"geometry", 1+2+3+4+5+6+7+8+9 },
					{"light", light}, {"space", 1}, {"air", 4}, {"water", 7}, {"fire", 3}, { "earth", 4 },
					{"wood", 8+7+4}, {"metal", 4+2+1+14},
					{"electricity", pow(9,9)}, {"plasma", pow(9,9)+pow(7,7)+pow(5,5)}, {"magma", pow(4,4)+pow(5,5)+pow(3,3) }, {"oil", pow(4,4)+pow(7,7)},
					{"gas", pow(4,4)+pow(4,4)+11},
					{"sun", light*5}, {"moon", light*4}, {"stars", light*18},
					{"clouds", 7+4+8},
					{"rainbow", numerology(pow(light, 9)+colours["red"]+colours["purple"]+colours["blue"]+colours["pink"]+colours["yellow"]+colours["green"]+colours["white"])},
					{"core", spiral_numerology(pow(5, 5)*pow(3,3)+8, 8*5*3, 8*5*3, 9) },
					{"crystals", 4*16}, {"gold", 4*5}, {"silver", 4*2}, {"diamonds", 4*16},					
					{"seeds", pow(9,9)+4}, {"grass", 4+colours["green"]}, {"flowers", 4+colours["green"]+colours["yellow"]}, 
					{"plants", 4*1*2}, {"animals", 4*1*3}, {"people", 4*1*4},
					{"pyramid_castings", 1*forward_spiral_numerology(pow(4, 7), pow(5, 5), pow(4, 4), 2) * (9*16)}, 
					{"center_of_the_sun", spiral_numerology(1+2+3+4+5+6+7+8+9, 1+2+3+4+5+6+7+8+9, 1+2+3+4+5+6+7+8+9, 45, 8*128) },	
					};
