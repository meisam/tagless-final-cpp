#ifndef CPP_ALGEBRA_MUL_H
#define CPP_ALGEBRA_MUL_H

#include <concepts>
#include <optional>

namespace algebra {

  template<typename Rep>
  concept Mul = requires(Rep rep, std::optional<int> a, std::optional<int> b) {
    {rep.mul(a, b)} -> std::same_as<std::optional<int>>;
  };

}  // namespace algebra

#endif  // CPP_ALGEBRA_MUL_H