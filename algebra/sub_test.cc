#include "sub.h"
#include <gtest/gtest.h>

namespace {

struct ValueSemanticsSub {
  auto sub(std::optional<int> a, std::optional<int> b) -> std::optional<int> {
    if (!a.has_value() || !b.has_value()) {
      return std::nullopt;
    }
    return a.value() - b.value();
  }
};

struct PointerSub {
  auto sub(int *a, int *b) -> std::optional<int> {
    if (a == nullptr || b == nullptr) {
      return std::nullopt;
    }
    return *a - *b;
  }
};

} // namespace

TEST(SubTest, ValueSemanticsSub_should_be_valid) {
  static_assert(algebra::Sub<ValueSemanticsSub> &&
                "ValueSemanticsSub should be a valid sub");
}

TEST(SubTest, PointerSub_should_be_invalid) {
  static_assert(!algebra::Sub<PointerSub> &&
                "PointerSub should not be a valid sub");
}