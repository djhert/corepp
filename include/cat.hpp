#ifndef __CORECAT_HPP__
#define __CORECAT_HPP__

#include "cmd.hpp"

#include <string>
namespace corepp {
class cat : public cmd {
public:
	cat() = default;
	~cat() = default;
	int Run(int argc, char *argv[]) override;
};
} // namespace corepp

#endif
