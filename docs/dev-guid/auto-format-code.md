# Dev Guide

## How to format the C++ souce code:

Use the `tools/format` alias to format the C++ code files:

```bash
# Format specific files in-place
bazel run //tools/format -- -i $PWD/main.cc

# Format all C++ files in the repository in-place
bazel run //tools/format -- -i $PWD/main.cc $(find $PWD -type f \( -name "*.cc" -o -name "*.h" \) ! -path "*/bazel-*")

# Run formatting checks (useful for CI)
bazel run //tools/format -- --dry-run --Werror $PWD/main.cc

# Run clang-tidy directly
bazel run //tools/format:clang-tidy -- $PWD/main.cc
```

## How to format Bazel (Starlark) files:

Use the `tools/format:buildifier` target to format all Starlark files (`BUILD.bazel`, `WORKSPACE`, `MODULE.bazel`, `.bzl`) in the repository:

```bash
# Format all Bazel files in the repository in-place
bazel run //tools/format:buildifier

# Run formatting checks (useful for CI)
bazel test //tools/format:buildifier_test
```