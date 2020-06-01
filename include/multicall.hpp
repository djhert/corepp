#ifdef MULTI_CALL
#ifndef __MULTICALL_HPP__
#define __MULTICALL_HPP__

#include <algorithm>

#include "cmd.hpp"
#include "corepp.hpp"

#include "cat.hpp"
#include "mkdir.hpp"

namespace corepp {

class imulticmd {
public:
	virtual ~imulticmd() = default;
	virtual std::unique_ptr<cmd> Create() const = 0;
};

class multicall {
public:
	static multicall &Instance();

	std::unique_ptr<cmd> Call(const std::string &name);

	void Register(const std::string &name, imulticmd *command);

private:
	multicall() = default;
	~multicall();
	multicall(const multicall &other);
	multicall &operator=(const multicall &other);

	std::unordered_map<std::string, imulticmd *> _commands;
};

template <typename T>
class multicmd : public imulticmd {
public:
	multicmd(const std::string &name) {
		multicall::Instance().Register(name, this);
	}
	std::unique_ptr<cmd> Create() const override {
		return std::unique_ptr<cmd>(new T());
	}
};

} // namespace corepp
#endif
#endif