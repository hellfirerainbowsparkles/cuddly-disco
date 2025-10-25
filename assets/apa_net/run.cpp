#include "./apa_net.h"

#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

int main( int argc, char *argv[] )  {

    std::filesystem::path p = "foo.c";
    std::cout << "Current path is " << std::filesystem::current_path() << '\n';
    std::cout << "Absolute path for " << p << " is " << fs::absolute(p) << '\n';

if( argc == 4 ) {

	run_net(argv[1], argv[2], argv[3]);
	
}
else {
	std::cout << "[success_file] [fail_file] [out_file]\n";
}

}
