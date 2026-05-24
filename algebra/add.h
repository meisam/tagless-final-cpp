#ifndef CPP_ALGEBRA_ADD_H
#define CPP_ALGEBRA_ADD_H

#include <concepts>
#include <optional>

namespace algebra {

template <typename Rep, typename A>
concept Add = requires(Rep rep, std::optional<A> a, std::optional<A> b) {
  { rep.add(a, b) } -> std::same_as<std::optional<A>>;
};

} // namespace algebra

#endif // CPP_ALGEBRA_ADD_H
