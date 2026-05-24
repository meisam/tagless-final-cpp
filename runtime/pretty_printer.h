#ifndef CPP_RUNTIME_PRETTY_PRINTER_H
#define CPP_RUNTIME_PRETTY_PRINTER_H

#include <optional>
#include <string>

namespace runtime {

struct PrettyPrinter {
  auto literal(int n) -> std::optional<std::string>;
  auto add(std::optional<std::string> a, std::optional<std::string> b)
      -> std::optional<std::string>;
  auto mul(std::optional<std::string> a, std::optional<std::string> b)
      -> std::optional<std::string>;
  auto sub(std::optional<std::string> a, std::optional<std::string> b)
      -> std::optional<std::string>;
  auto div(std::optional<std::string> a, std::optional<std::string> b)
      -> std::optional<std::string>;
};

} // namespace runtime

#endif // CPP_RUNTIME_PRETTY_PRINTER_H
