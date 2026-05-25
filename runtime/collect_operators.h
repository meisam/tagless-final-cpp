#ifndef CPP_RUNTIME_COLLECT_OPERATORS_H
#define CPP_RUNTIME_COLLECT_OPERATORS_H

#include <vector>

namespace runtime {

struct CollectOperators {
  auto literal(int n) -> std::vector<char>;
  auto add(std::vector<char> a, std::vector<char> b) -> std::vector<char>;
  auto mul(std::vector<char> a, std::vector<char> b) -> std::vector<char>;
  auto sub(std::vector<char> a, std::vector<char> b) -> std::vector<char>;
  auto div(std::vector<char> a, std::vector<char> b) -> std::vector<char>;
};

} // namespace runtime

#endif // CPP_RUNTIME_COLLECT_OPERATORS_H
