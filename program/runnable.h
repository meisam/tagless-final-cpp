#ifndef CPP_PROGRAM_RUNNABLE_H
#define CPP_PROGRAM_RUNNABLE_H

#include <concepts>
#include <optional>

namespace program {

template <template <typename> typename F, typename P, typename A>
concept Runnable = requires(P p, A a) {
  { p.run() } -> std::same_as<F<A>>;
};

} // namespace program

#endif // CPP_PROGRAM_RUNNABLE_H
