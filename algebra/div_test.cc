#include <gtest/gtest.h>
#include "div.h"

namespace {

struct ValueSemanticsDiv {
  auto div(std::optional<int> a, std::optional<int> b) -> std::optional<int> {
    if (!a.has_value() || !b.has_value()) {
      return std::nullopt;
    }
    if (b.value() == 0) {
      return std::nullopt;
    }
    return a.value() / b.value();
  }
};

struct PointerDiv {
  auto div(int *a, int *b) -> std::optional<int> {
    if (a == nullptr || b == nullptr) {
      return std::nullopt;
    }
    if (*b == 0) {
      return std::nullopt;
    }
    return *a / *b;
  }
};

}  // namespace

TEST(DivTest, ValueSemanticsDiv_should_be_valid) {
  static_assert(algebra::Div<ValueSemanticsDiv>
    && "ValueSemanticsDiv should be a valid div");
}

TEST(DivTest, PointerDiv_should_be_invalid) {
  static_assert(!algebra::Div<PointerDiv>
    && "PointerDiv should not be a valid div");
}