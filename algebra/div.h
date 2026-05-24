#ifndef CPP_ALGEBRA_DIV_H
#define CPP_ALGEBRA_DIV_H

#include <concepts>
#include <optional>

namespace algebra {

template <typename Rep, typename A>
concept Div = requires(Rep rep, std::optional<A> a, std::optional<A> b) {
  { rep.div(a, b) } -> std::same_as<std::optional<A>>;
};

} // namespace algebra

#endif // CPP_ALGEBRA_DIV_H