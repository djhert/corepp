#ifndef __CMD_HPP__
#define __CMD_HPP__

#include <memory>

#include "corepp.hpp"

namespace corepp {
class cmd {
public:
	cmd() = default;
	virtual ~cmd() = default;
	virtual int Run(int argc, char *argv[]);

	static void badFlag(const char *argv0, const char &flag);
};
} // namespace corepp
#endif
