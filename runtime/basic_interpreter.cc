#include <optional>

#include "runtime/basic_interpreter.h"

namespace runtime {

auto BasicInterpreter::literal(int n) -> std::optional<int> { return n; }

auto BasicInterpreter::add(std::optional<int> a, std::optional<int> b)
    -> std::optional<int> {
  if (!a.has_value() || !b.has_value())
    return std::nullopt;
  return a.value() + b.value();
}

auto BasicInterpreter::mul(std::optional<int> a, std::optional<int> b)
    -> std::optional<int> {
  if (!a.has_value() || !b.has_value())
    return std::nullopt;
  return a.value() * b.value();
}

auto BasicInterpreter::sub(std::optional<int> a, std::optional<int> b)
    -> std::optional<int> {
  if (!a.has_value() || !b.has_value())
    return std::nullopt;
  return a.value() - b.value();
}

auto BasicInterpreter::div(std::optional<int> a, std::optional<int> b)
    -> std::optional<int> {
  if (!a.has_value() || !b.has_value() || b.value() == 0)
    return std::nullopt;
  return a.value() / b.value();
}

} // namespace runtime