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

template <typename P, typename A>
  requires Add<P, A> && Literal<P, A> && Mul<P, A> && Sub<P, A> && Div<P, A>
struct TaxiCabNumberProgram {
  auto run() -> std::optional<A> {
    P p;
    // 1729 = 1^3 + 12^3 = 9^3 + 10^3
    return p.literal(1729);
  }
};

template <typename P, typename A>
  requires Add<P, A> && Literal<P, A> && Mul<P, A> && Sub<P, A> && Div<P, A>
struct TaxiCabNumberProgram1 {
  auto run() -> std::optional<A> {
    P p;
    // 1729 = 1^3 + 12^3 = 9^3 + 10^3
    return p.add(p.mul(p.mul(p.literal(1), p.literal(1)), p.literal(1)),
                 p.mul(p.mul(p.literal(12), p.literal(12)), p.literal(12)));
  }
};

template <typename P, typename A>
  requires Add<P, A> && Literal<P, A> && Mul<P, A> && Sub<P, A> && Div<P, A>
struct TaxiCabNumberProgram2 {
  auto run() -> std::optional<A> {
    P p;
    // 1729 = 1^3 + 12^3 = 9^3 + 10^3
    return p.add(p.mul(p.mul(p.literal(9), p.literal(9)), p.literal(9)),
                 p.mul(p.mul(p.literal(10), p.literal(10)), p.literal(10)));
  }
};

} // namespace

TEST(RamanujanNumberTest, TaxiCabNumberProgram1_should_be_valid) {
  static_assert(
      program::Runnable<TaxiCabNumberProgram1<BasicInterpreter, int>, int> &&
      "TaxiCabNumberProgram1 should be a valid program");
}

TEST(RamanujanNumberTest, TaxiCabNumberProgram2_should_be_valid) {
  static_assert(
      program::Runnable<TaxiCabNumberProgram2<BasicInterpreter, int>, int> &&
      "TaxiCabNumberProgram2 should be a valid program");
}

TEST(RamanujanNumberTest, ResultShouldMatch) {
  TaxiCabNumberProgram<BasicInterpreter, int> p0;
  TaxiCabNumberProgram1<BasicInterpreter, int> p1;
  TaxiCabNumberProgram2<BasicInterpreter, int> p2;
  EXPECT_THAT(std::vector({p0.run(), p1.run(), p2.run()}), testing::Each(1729));
}

TEST(RamanujanNumberTest, PrettyPrinterTest) {
  TaxiCabNumberProgram1<PrettyPrinter, std::string> p;
  EXPECT_EQ(p.run(), "(((1 * 1) * 1) + ((12 * 12) * 12))");
}
