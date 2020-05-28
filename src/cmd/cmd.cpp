#ifdef MULTI_CALL
#include "corepp.hpp"

#include "cat/cat.hpp"
#include "mkdir/mkdir.hpp"

using namespace corepp;

int main(int argc, char *argv[]) {
	std::cout << "Using: " << argv[0] << std::endl;
	cat::Cat();
	mkdir::Mkdir();
}

#endif