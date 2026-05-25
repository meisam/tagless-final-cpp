#include <vector>

#include "algebra/add.h"
#include "algebra/div.h"
#include "algebra/literal.h"
#include "algebra/mul.h"
#include "algebra/sub.h"
#include "program/runnable.h"
#include "runtime/basic_interpreter.h"
#include "runtime/pretty_printer.h"
#include "gmock/gmock-matchers.h"
#include <gtest/gtest.h>

namespace {

using algebra::Add;
using algebra::Div;
using algebra::Literal;
using algebra::Mul;
using algebra::Sub;
using program::Runnable;
using runtime::BasicInterpreter;
using runtime::PrettyPrinter;

template <template <typename> typename F, typename P, typename A>
  requires Add<F, P, A> && Literal<F, P, A> && Mul<F, P, A> && Sub<F, P, A> &&
           Div<F, P, A>
struct TaxiCabNumberProgram {
  auto run() -> F<A> {
    P p;
    // 1729 = 1^3 + 12^3 = 9^3 + 10^3
    return p.literal(1729);
  }
};

template <template <typename> typename F, typename P, typename A>
  requires Add<F, P, A> && Literal<F, P, A> && Mul<F, P, A> && Sub<F, P, A> &&
           Div<F, P, A>
struct TaxiCabNumberProgram1 {
  auto run() -> F<A> {
    P p;
    // 1729 = 1^3 + 12^3 = 9^3 + 10^3
    return p.add(p.mul(p.mul(p.literal(1), p.literal(1)), p.literal(1)),
                 p.mul(p.mul(p.literal(12), p.literal(12)), p.literal(12)));
  }
};

template <template <typename> typename F, typename P, typename A>
  requires Add<F, P, A> && Literal<F, P, A> && Mul<F, P, A> && Sub<F, P, A> &&
           Div<F, P, A>
struct TaxiCabNumberProgram2 {
  auto run() -> F<A> {
    P p;
    // 1729 = 1^3 + 12^3 = 9^3 + 10^3
    return p.add(p.mul(p.mul(p.literal(9), p.literal(9)), p.literal(9)),
                 p.mul(p.mul(p.literal(10), p.literal(10)), p.literal(10)));
  }
};

} // namespace

TEST(RamanujanNumberTest, TaxiCabNumberProgram1_should_be_valid) {
  static_assert(
      program::Runnable<
          std::optional,
          TaxiCabNumberProgram1<std::optional, BasicInterpreter, int>, int> &&
      "TaxiCabNumberProgram1 should be a valid program");
}

TEST(RamanujanNumberTest, TaxiCabNumberProgram2_should_be_valid) {
  static_assert(
      program::Runnable<
          std::optional,
          TaxiCabNumberProgram2<std::optional, BasicInterpreter, int>, int> &&
      "TaxiCabNumberProgram2 should be a valid program");
}

TEST(RamanujanNumberTest, ResultShouldMatch) {
  TaxiCabNumberProgram<std::optional, BasicInterpreter, int> p0;
  TaxiCabNumberProgram1<std::optional, BasicInterpreter, int> p1;
  TaxiCabNumberProgram2<std::optional, BasicInterpreter, int> p2;
  EXPECT_THAT(std::vector({p0.run(), p1.run(), p2.run()}), testing::Each(1729));
}

TEST(RamanujanNumberTest, PrettyPrinterTest) {
  TaxiCabNumberProgram1<std::optional, PrettyPrinter, std::string> p;
  EXPECT_EQ(p.run(), "(((1 * 1) * 1) + ((12 * 12) * 12))");
}
