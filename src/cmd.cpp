#include "cmd.hpp"

using namespace corepp;

#ifdef _DEBUG
void *operator new(size_t size) {
	std::cout << "[new] size: " << size << std::endl;
	void *p = malloc(size);
	return p;
}

void operator delete(void *p)noexcept {
	std::cout << "[delete]" << std::endl;
	free(p);
}
#endif

void cmd::badFlag(const char *argv0, const char &flag) {
	std::cerr << argv0 << ": invalid option -- \'" << flag << "\'\nTry \'"
			  << argv0 << " -h\' for more information" << std::endl;
}

int cmd::Run(int argc, char *argv[]) {
	return -1;
}