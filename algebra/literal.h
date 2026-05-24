#ifndef CPP_ALGEBRA_LITERAL_H
#define CPP_ALGEBRA_LITERAL_H

#include <concepts>
#include <optional>

namespace algebra {

template <typename Rep>
concept Literal = requires(Rep a, int n) {
  { a.literal(n) } -> std::same_as<std::optional<int>>;
};

}

#endif // CPP_ALGEBRA_LITERAL_H
