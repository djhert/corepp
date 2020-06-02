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

	template <typename T>
	static std::unique_ptr<cmd> Create() {
		return std::unique_ptr<cmd>(new T());
	}
};
} // namespace corepp
#endif
