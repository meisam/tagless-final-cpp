#ifndef CPP_ALGEBRA_MUL_H
#define CPP_ALGEBRA_MUL_H

#include <concepts>
#include <optional>

namespace algebra {

template <typename Rep, typename A>
concept Mul = requires(Rep rep, std::optional<A> a, std::optional<A> b) {
  { rep.mul(a, b) } -> std::same_as<std::optional<A>>;
};

} // namespace algebra

#endif // CPP_ALGEBRA_MUL_H