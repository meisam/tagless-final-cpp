#include "add.h"
#include <gtest/gtest.h>

namespace {

// A simple test case
struct ValueSemanticsAdd {
  auto add(std::optional<int> a, std::optional<int> b) -> std::optional<int> {
    if (!a.has_value() || !b.has_value()) {
      return std::nullopt;
    }
    return a.value() + b.value();
  }
};

struct PointerAdd {
  auto add(int *a, int *b) -> std::optional<int> {
    if (a == nullptr || b == nullptr) {
      return std::nullopt;
    }
    return *a + *b;
  }
};

} // namespace

TEST(AddTest, ValueSemanticsAdd_should_be_valid) {
  static_assert(algebra::Add<ValueSemanticsAdd> &&
                "ValueSemanticsAdd should be a valid add");
}

TEST(AddTest, PointerAdd_should_be_invalid) {
  static_assert(!algebra::Add<PointerAdd> &&
                "PointerAdd should not be a valid add");
}