#ifndef CPP_ALGEBRA_DIV_H
#define CPP_ALGEBRA_DIV_H

#include <concepts>
#include <optional>

namespace algebra {

template <typename Rep>
concept Div = requires(Rep rep, std::optional<int> a, std::optional<int> b) {
  { rep.div(a, b) } -> std::same_as<std::optional<int>>;
};

} // namespace algebra

#endif // CPP_ALGEBRA_DIV_H