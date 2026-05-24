#ifndef CPP_ALGEBRA_SUB_H
#define CPP_ALGEBRA_SUB_H

#include <concepts>
#include <optional>

namespace algebra {

template <typename Rep, typename A>
concept Sub = requires(Rep rep, std::optional<A> a, std::optional<A> b) {
  { rep.sub(a, b) } -> std::same_as<std::optional<A>>;
};

} // namespace algebra

#endif // CPP_ALGEBRA_SUB_H