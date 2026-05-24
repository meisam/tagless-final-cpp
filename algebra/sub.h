#ifndef CPP_ALGEBRA_SUB_H
#define CPP_ALGEBRA_SUB_H

#include <concepts>
#include <optional>

namespace algebra {

template <typename Rep>
concept Sub = requires(Rep rep, std::optional<int> a, std::optional<int> b) {
  { rep.sub(a, b) } -> std::same_as<std::optional<int>>;
};

} // namespace algebra

#endif // CPP_ALGEBRA_SUB_H