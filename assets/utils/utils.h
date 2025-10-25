#ifndef _UTILS_
#define _UTILS_

#include <string>
#include <iostream>
#include <fstream>
#include <dirent.h> 
#include <stdio.h> 
#include <vector>
#include "./numerology.h"
#include "./astar/AStar.cpp"
#include "./dstar/Dstar.cpp"

bool str_replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

int download(std::string url, std::string file, int timeout = 30) {

		str_replace(file, "/", "_");

		char cmd[100] = "";
		sprintf(cmd, "curl -L --keepalive-time 60 -m %d %s > data/%s", timeout, url.c_str(), file.c_str()); 
		int r = system(cmd);

		printf("%s\n", cmd);

		char cmd2[100];
		sprintf(cmd2, "sed -n 's/.*href=\"https\\([^\"]*\\).*/\\1/p' data/%s > data/%s_urls.txt", file.c_str(), file.c_str());
		system(cmd2);
		
		char cmd3[100];
		sprintf(cmd3, "sed -n 's/.*\"\\([^\"]*\\).*/\\1.jpg/p' data/%s > data/%s_jpgs.txt", file.c_str(), file.c_str());
		system(cmd3);		

		char cmd4[100];
		sprintf(cmd4, "sed -n 's/.*\"\\([^\"]*\\).*/\\1.mpg/p' data/%s > data/%s_mpgs.txt", file.c_str(), file.c_str());
		system(cmd4);	
		
	return 0;
}
/*
char read_file(std::string file_name) {
	std::fstream file0(file_name, std::ios::in | std::ios::out | std::ios::binary);
	char ka;
	file0.read(&ka, 0);
	return ka;
}
*/
std::string read_string_from_file(std::string file_name, int n=1) {
	std::ifstream file0;
	file0.open(file_name);
	std::string ka;
	for (int i=0; i<n; i++) {
	file0 >> ka;	
	}
	return ka;
}

void write_string_to_file(std::string file_name, std::string str) {
    std::ofstream log(file_name, std::ios_base::trunc | std::ios_base::out);
    log << str << "\n";
}

// . va
void random_seed() {

char r = read_file("./hung.ka");
char r2 = read_file("/proc/stat");
char r3 = read_file("/proc/net/arp");
char r4 = read_file("/proc/net/raw");

int i = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
int i2 = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);

time_t current   = time(0);
time_t inOneHour = current + (i2*i); 

srand(r + r2 + r3 + r4 + inOneHour);

}

double random_double(double start, double end) {

double uniform = (double) rand() / (double) RAND_MAX;
double r = (double) ((start - end)*uniform) + end;
return r;

}

std::vector<std::string> list_files(std::string directory) {

  DIR *d;
  struct dirent *dir;
  d = opendir(directory.c_str());
  std::vector<std::string> files;
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
      files.push_back(dir->d_name);
    }
    closedir(d);
  }
  
  return files;

}

void d_star_cast() {
	 Dstar *dstar = new Dstar();
	 list<state> mypath;

    double w = random_double(1,100);
    double h = random_double(1,100);

	 dstar->init(0,0,(int) w,(int) h);         // set start to (0,0) and goal to (10,5)

   double ntx =  (int) random_double(1,w);
	double nty =  (int) random_double(1,h);

	 dstar->updateCell(ntx, nty,-1);     // set cell (3,4) to be non traversable
	 
   double cost = (int) random_double(1,100);	 

   double ctx =  (int) random_double(1,w);
	double cty =  (int) random_double(1,h);
	 
	 dstar->updateCell(ctx, cty,cost); // set set (2,2) to have cost 42.432

	 dstar->replan();               // plan a path
	 mypath = dstar->getPath();     // retrieve path


   double stx =  (int) random_double(1,w);
	double sty =  (int) random_double(1,h);
	 
	 dstar->updateStart(stx, sty);      // move start to (10,2)
	 dstar->replan();               // plan a path
	 mypath = dstar->getPath();     // retrieve path


   double gtx =  (int) random_double(1,w);
	double gty =  (int) random_double(1,h);
	 
	 dstar->updateGoal(gtx, gty);        // move goal to (0,1)
	 dstar->replan();               // plan a path
	 mypath = dstar->getPath();     // retrieve path
}

// . va
void a_star_cast() {
    char director = read_file("../tokyo_ai/run.out"); // .va

    AStar::Generator generator;
    
    // Set 2d map size.
    double w = random_double(1,100);
    double h = random_double(1,100);
    generator.setWorldSize({(int) w, (int) h});
    
    
    // You can use a few heuristics : manhattan, euclidean or octagonal.
    double r = random_double(1,100);
    if (r < 33) {
  	  generator.setHeuristic(AStar::Heuristic::euclidean);
    } else if (r < 66) {
    	generator.setHeuristic(AStar::Heuristic::manhattan);
    } else {
    	generator.setHeuristic(AStar::Heuristic::octagonal);
    }

    r = random_double(1,100);    
    if (r > 50) {
    	generator.setDiagonalMovement(true);
    } else {
    	generator.setDiagonalMovement(false);    
    }
    //This method returns vector of coordinates from target to source.
    int sx = (int) random_double(0, w);
    int sy = (int) random_double(0, h);
    int ex = (int) random_double(0, w);
    int ey = (int) random_double(0, h);    
    auto path = generator.findPath({sx, sy}, {ex, ey});
    d_star_cast(); // . va
}	


#endif
