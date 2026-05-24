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

# Run clang-tidy directly on specific files
bazel run //tools/format:clang-tidy -- $PWD/main.cc
```

## How to use Clang-Tidy for Static Analysis

We expose the hermetic `clang-tidy` binary from our LLVM toolchain via the `//tools/format:clang-tidy` alias.

Because `clang-tidy` requires a compilation database to resolve headers and compilation flags correctly, you must first ensure that your compilation database is up to date (by running `bazel run //:compile_commands`).

### 1. Running Clang-Tidy on a specific file
To run static analysis on a specific file using the compilation database generated at the project root:

```bash
bazel run //tools/format:clang-tidy -- -p=$PWD $PWD/main.cc
```

### 2. Running Clang-Tidy on all C++ source files
You can find and run analysis across all source and header files in the project (excluding Bazel's build directory):

```bash
bazel run //tools/format:clang-tidy -- -p=$PWD $(find $PWD -type f \( -name "*.cc" -o -name "*.h" \) ! -path "*/bazel-*")
```

### 3. Automatically fixing lint/style suggestions
To let `clang-tidy` automatically apply compiler and modernize fixes in-place, pass the `-fix` flag:

```bash
bazel run //tools/format:clang-tidy -- -p=$PWD -fix $PWD/main.cc
```

### 4. Specifying specific checks
To enable or disable specific rules manually (for example, to check for C++20 modernize rules or readability suggestions):

```bash
bazel run //tools/format:clang-tidy -- -p=$PWD --checks="modernize-*,readability-*,-modernize-use-trailing-return-type" $PWD/main.cc
```

### 5. Filtering header files
By default, `clang-tidy` only reports warnings in the main source file. If you want to check warnings in your header files as well, use the `-header-filter` flag:

```bash
bazel run //tools/format:clang-tidy -- -p=$PWD -header-filter="^$PWD/.*" $PWD/main.cc
```


## How to format Bazel (Starlark) files:

Use the `tools/format:buildifier` target to format all Starlark files (`BUILD.bazel`, `WORKSPACE`, `MODULE.bazel`, `.bzl`) in the repository:

```bash
# Format all Bazel files in the repository in-place
bazel run //tools/format:buildifier

# Run formatting checks (useful for CI)
bazel test //tools/format:buildifier_test
```