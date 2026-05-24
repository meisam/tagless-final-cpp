#include <gtest/gtest.h>
#include "runnable.h"

namespace {

struct DummyRunnable {
  auto run() -> std::optional<int> {
    return std::optional(42);
  }
};

struct NotARunnable {
  auto run() -> int {
    return 42;
  }
};

struct WrongTypeRunnable {
  auto run() -> std::optional<double> {
    return std::optional<double>(42.0);
  }
};

}  // namespace

TEST(RunnableTest, DummyRunnable_should_be_valid) {
  static_assert(program::Runnable<DummyRunnable, int>
    && "DummyRunnable should be a valid runnable");
}

TEST(RunnableTest, NotARunnable_should_be_invalid) {
  static_assert(!program::Runnable<NotARunnable, int>
    && "NotARunnable should not be a valid runnable");
}

TEST(RunnableTest, WrongTypeRunnable_should_be_invalid) {
  static_assert(!program::Runnable<WrongTypeRunnable, int>
    && "WrongTypeRunnable should not be a valid runnable");
}
