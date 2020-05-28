#include "cat/cat.hpp"

using namespace corepp;

#ifdef SINGLE_CALL
int main(int argc, char *argv[]) {
	cat::Cat();
	return 0;
}
#endif

int cat::Cat() {
	std::cout << "Hello from cat!" << std::endl;
	return 0;
}
