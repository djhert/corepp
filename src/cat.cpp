#include "cat.hpp"

using namespace corepp;

#ifdef SINGLE_CALL
int main(int argc, char *argv[]) {
	std::unique_ptr<cmd> cur = cmd::Create<cat>();
	cur->Run(argc, argv);
	return 0;
}
#endif

#ifdef MULTI_CALL
#include "multicall.hpp"
bool cat::_reg = multicall::Register("cat", cmd::Create<cat>);
#endif

int cat::Run(int argc, char *argv[]) {
	static char *argv0 = *argv;
	std::cout << "Hello from: " << argv0 << std::endl;
	return 0;
}
