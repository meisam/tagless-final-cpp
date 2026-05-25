#ifndef CPP_ALGEBRA_DIV_H
#define CPP_ALGEBRA_DIV_H

#include <concepts>
#include <optional>

namespace algebra {

template <template <typename> typename F, typename Rep, typename A>
concept Div = requires(Rep rep, F<A> a, F<A> b) {
  { rep.div(a, b) } -> std::same_as<F<A>>;
};

} // namespace algebra

#endif // CPP_ALGEBRA_DIV_H