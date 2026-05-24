#include "runtime/pretty_printer.h"
#include <optional>
#include <ostream>

namespace runtime {

auto PrettyPrinter::literal(int n) -> std::optional<std::string> {
  return std::to_string(n);
}

auto PrettyPrinter::add(std::optional<std::string> a,
                        std::optional<std::string> b)
    -> std::optional<std::string> {
  if (a.has_value() && b.has_value()) {
    return std::optional<std::string>("(" + a.value() + " + " + b.value() +
                                      ")");
  }
  return std::nullopt;
}

auto PrettyPrinter::mul(std::optional<std::string> a,
                        std::optional<std::string> b)
    -> std::optional<std::string> {
  if (a.has_value() && b.has_value()) {
    return std::optional<std::string>("(" + a.value() + " * " + b.value() +
                                      ")");
  }
  return std::nullopt;
}

auto PrettyPrinter::sub(std::optional<std::string> a,
                        std::optional<std::string> b)
    -> std::optional<std::string> {
  if (a.has_value() && b.has_value()) {
    return std::optional("(" + a.value() + " - " + b.value() + ")");
  }
  return std::nullopt;
}

auto PrettyPrinter::div(std::optional<std::string> a,
                        std::optional<std::string> b)
    -> std::optional<std::string> {
  if (a.has_value() && b.has_value()) {
    return std::optional("(" + a.value() + " / " + b.value() + ")");
  }
  return std::nullopt;
}

} // namespace runtime