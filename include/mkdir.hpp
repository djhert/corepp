#ifndef __COREMKDIR_HPP__
#define __COREMKDIR_HPP__

#include "cmd.hpp"

#include <filesystem>

namespace corepp {
class mkdir : public cmd {
public:
	mkdir(){};
	~mkdir(){};
	int Run(int argc, char *argv[]) override;
#ifdef MULTI_CALL
private:
	static bool _reg;
#endif
};
} // namespace corepp

#endif