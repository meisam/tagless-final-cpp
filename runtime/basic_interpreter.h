#ifndef CPP_RUNTIME_BASIC_INTERPRETER_H
#define CPP_RUNTIME_BASIC_INTERPRETER_H

#include <optional>

namespace runtime {

struct BasicInterpreter {
  auto literal(int n) -> std::optional<int>;
  auto add(std::optional<int> a, std::optional<int> b) -> std::optional<int>;
  auto mul(std::optional<int> a, std::optional<int> b) -> std::optional<int>;
  auto sub(std::optional<int> a, std::optional<int> b) -> std::optional<int>;
  auto div(std::optional<int> a, std::optional<int> b) -> std::optional<int>;
};

} // namespace runtime

#endif // CPP_RUNTIME_BASIC_INTERPRETER_H
