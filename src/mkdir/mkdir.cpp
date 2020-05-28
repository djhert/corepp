#include "mkdir/mkdir.hpp"

using namespace corepp;

#ifdef SINGLE_CALL
int main(int argc, char *argv[]) {
	mkdir::Mkdir();
	return 0;
}
#endif

int mkdir::Mkdir() {
	std::cout << "Hello from mkdir!" << std::endl;
	return 0;
}
