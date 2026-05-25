#include "literal.h"
#include <gtest/gtest.h>

namespace {

struct ValueSemanticsLiteral {
  auto literal(int n) -> std::optional<int> {
    if (n == 0)
      return 1;
    return {};
  }
};

struct PointerLiteral {
  auto literal(int *n) -> std::optional<int> {
    if (n == nullptr)
      return std::nullopt;
    return *n;
  }
};

} // namespace

TEST(LiteralTest, ValueLiteral_should_be_valid) {
  static_assert(algebra::Literal<std::optional, ValueSemanticsLiteral, int> &&
                "ValueSemanticsLiteral should be a valid literal");
}

TEST(LiteralTest, PointerLiteral_should_be_invalid) {
  static_assert(!algebra::Literal<std::optional, PointerLiteral, int> &&
                "PointerLiteral should not be a valid literal");
}