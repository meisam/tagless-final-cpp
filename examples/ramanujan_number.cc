#include "algebra/add.h"
#include "algebra/div.h"
#include "algebra/literal.h"
#include "algebra/mul.h"
#include "algebra/sub.h"
#include "program/runnable.h"
#include "runtime/basic_interpreter.h"


namespace examples {

namespace {

using algebra::Add;
using algebra::Div;
using algebra::Literal;
using algebra::Mul;
using algebra::Sub;
using program::Runnable;
using runtime::BasicInterpreter;

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

}  // namespace

int program9cubed_plus_10cubed(){
  return examples::TaxiCabNumberProgram2<BasicInterpreter, int>().run().value();

}

}  // namespace examples