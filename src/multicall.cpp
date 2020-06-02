#ifdef MULTI_CALL

#include "multicall.hpp"

using namespace corepp;

int main(int argc, char *argv[]) {
	std::cout << "Using: " << argv[0] << std::endl;
	std::string _usecmd(argv[0]);
	std::size_t _found = _usecmd.find_last_of("/\\");
	const char *_used = _usecmd.substr(_found + 1).c_str();
	std::cout << "Command: " << _used << std::endl;
	std::unique_ptr<cmd> _cmd = multicall::Instance().Call(_used);
	if (!_cmd) {
		std::cout << "[ERROR] No command \'" << _used << "\' is available"
				  << std::endl;
		return -1;
	}
	return _cmd->Run(argc, argv);
	return 0;
}

multicall::~multicall() {
	_commands.clear();
}

multicall &multicall::Instance() {
	static multicall instance;
	return instance;
}

std::unique_ptr<cmd> multicall::Call(const char *name) {
	auto i = _commands.find(name);
	if (i == _commands.end()) {
		return nullptr;
	}
	return i->second();
}

bool multicall::Register(const char *name, std::unique_ptr<cmd> (*f)()) {
	Instance()._commands[name] = f;
	std::cout << "[registering] " << name << std::endl;
	return true;
}

#endif
