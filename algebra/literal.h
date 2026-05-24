#ifndef CPP_ALGEBRA_LITERAL_H
#define CPP_ALGEBRA_LITERAL_H

#include <concepts>
#include <optional>

namespace algebra {

template <typename Rep, typename A>
concept Literal = requires(Rep a, int n) {
  { a.literal(n) } -> std::same_as<std::optional<A>>;
};

}

#endif // CPP_ALGEBRA_LITERAL_H
