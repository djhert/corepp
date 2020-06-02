#ifdef MULTI_CALL
#ifndef __MULTICALL_HPP__
#define __MULTICALL_HPP__

#include <algorithm>

#include "cmd.hpp"
#include "corepp.hpp"

#include "cat.hpp"
#include "mkdir.hpp"

namespace corepp {

class multicall {
public:
	static multicall &Instance();

	std::unique_ptr<cmd> Call(const char *name);

	static bool Register(const char *name, std::unique_ptr<cmd> (*f)());

private:
	multicall() = default;
	~multicall();
	multicall(const multicall &other) = delete;
	multicall &operator=(const multicall &other) = delete;

	std::unordered_map<const char *, std::unique_ptr<cmd> (*)()> _commands;
};

} // namespace corepp
#endif
#endif