#ifndef CPP_ALGEBRA_ADD_H
#define CPP_ALGEBRA_ADD_H

#include <concepts>
#include <optional>

namespace algebra {

  template<typename Rep>
  concept Add = requires(Rep rep, std::optional<int> a, std::optional<int> b) {
    {rep.add(a, b)} -> std::same_as<std::optional<int>>;
  };

}

#endif  // CPP_ALGEBRA_ADD_H
