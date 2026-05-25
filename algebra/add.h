#ifndef CPP_ALGEBRA_ADD_H
#define CPP_ALGEBRA_ADD_H

#include <concepts>
#include <optional>

namespace algebra {

template <template <typename> typename F, typename Rep, typename A>
concept Add = requires(Rep rep, F<A> a, F<A> b) {
  { rep.add(a, b) } -> std::same_as<F<A>>;
};

} // namespace algebra

#endif // CPP_ALGEBRA_ADD_H
