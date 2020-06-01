#ifdef MULTI_CALL

#include "multicall.hpp"

using namespace corepp;

int main(int argc, char *argv[]) {
	std::cout << "Using: " << argv[0] << std::endl;
	std::string _used(argv[0]);
	std::size_t _found = _used.find_last_of("/\\");
	_used = _used.substr(_found + 1);
	std::cout << "Command: " << _used << std::endl;
	std::unique_ptr<cmd> _cmd = multicall::Instance().Call(_used);
	if (!_cmd) {
		std::cout << "[ERROR] No command \'" << _used << "\' is available"
				  << std::endl;
		return -1;
	}
	return _cmd->Run(argc, argv);
}

multicall::~multicall() {
	_commands.clear();
}

multicall &multicall::Instance() {
	static multicall instance;
	return instance;
}

std::unique_ptr<cmd> multicall::Call(const std::string &name) {
	auto i = _commands.find(name);
	if (i == _commands.end()) {
		return nullptr;
	}
	return i->second->Create();
}

void multicall::Register(const std::string &name, imulticmd *command) {
	std::cout << "[registering] " << name << std::endl;
	_commands[name] = command;
}

#endif
