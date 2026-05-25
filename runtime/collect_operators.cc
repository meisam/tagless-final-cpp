#include "runtime/collect_operators.h"

#include <vector>

namespace runtime {

auto CollectOperators::literal(int n) -> std::vector<char> { return {}; }
auto CollectOperators::add(std::vector<char> a, std::vector<char> b)
    -> std::vector<char> {
  a.push_back('+');
  a.insert(a.end(), b.begin(), b.end());
  return a;
}
auto CollectOperators::mul(std::vector<char> a, std::vector<char> b)
    -> std::vector<char> {
  a.push_back('*');
  a.insert(a.end(), b.begin(), b.end());
  return a;
}
auto CollectOperators::sub(std::vector<char> a, std::vector<char> b)
    -> std::vector<char> {
  a.push_back('-');
  a.insert(a.end(), b.begin(), b.end());
  return a;
}
auto CollectOperators::div(std::vector<char> a, std::vector<char> b)
    -> std::vector<char> {
  a.push_back('/');
  a.insert(a.end(), b.begin(), b.end());
  return a;
}

} // namespace runtime