#include "common.h"

namespace ExtAPI {
std::map<std::string, std::set<std::tuple<char const *, void (*)(FunctionCallbackInfo<Value> const &)>>> Register::registry;
std::set<void (*)(Isolate *)> Register::injecteds;
} // namespace ExtAPI