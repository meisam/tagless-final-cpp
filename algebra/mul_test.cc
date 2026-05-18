#include <gtest/gtest.h>
#include "mul.h"

namespace {

struct ValueSemanticsMul {
  auto mul(std::optional<int> a, std::optional<int> b) -> std::optional<int> {
    if (!a.has_value() || !b.has_value()) {
      return std::nullopt;
    }
    return a.value() * b.value();
  }
};

struct PointerMul {
  auto mul(int *a, int *b) -> std::optional<int> {
    if (a == nullptr || b == nullptr) {
      return std::nullopt;
    }
    return *a * *b;
  }
};

}  // namespace

TEST(MulTest, ValueSemanticsMul_should_be_valid) {
  static_assert(algebra::Mul<ValueSemanticsMul>
     && "ValueSemanticsMul should be a valid mul");
}

TEST(MulTest, PointerMul_should_be_invalid) {
  static_assert(!algebra::Mul<PointerMul>
     && "PointerMul should not be a valid mul");
}