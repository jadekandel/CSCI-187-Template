# MyProject

A Qt desktop app template for CSCI 187 team projects. Each team uses this
repo as their starting point.

## One-time setup

1. Install [VS Code](https://code.visualstudio.com/), [CMake](https://cmake.org/download/),
   and [Qt](https://www.qt.io/download-qt-installer) (Widgets module, version 5).
2. In VS Code, sign in to GitHub using the account icon in the bottom-left
   corner of the window. **Do not create a Personal Access Token** — the
   account icon sign-in flow is all you need, and PATs are unnecessary for
   this course and easy to leak.
3. On GitHub, click **Use this template** on this repository to create your
   team's own copy.
4. Clone your team's new repository and open it in VS Code.

## Building and running locally

These are the exact same three commands CI runs on every push, so if they
pass locally they'll pass in CI too:

```
cmake -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## What to change vs. what to leave alone

| Change this | Leave this alone |
|---|---|
| The project name at the top of `CMakeLists.txt` (`# CHANGE THIS`) | `tests/doctest.h` |
| The two file lists in `CMakeLists.txt` (`# EDIT THIS LIST:`, for the `app` and `test_build` targets) | `.gitignore` |
| Files in `src/` (add your own model/view/controller classes; delete `counter.h`/`counter.cpp` once you have your own) | |
| Files in `tests/` (add a `test_*.cpp` per class you want covered) | |
| The dependency install step in `.github/workflows/ci.yml` (add `apt-get install` lines for any library you use) | |

Only **one** test file in the whole project may have
`#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN` at the top — it's what generates
the test binary's `main()`. If two files define it, or if it ends up in the
same target as `src/main.cpp`, the build will fail to link.

## Writing a test

Each test file includes `"doctest.h"` and the header of the class it's
testing, then declares one or more `TEST_CASE`s made of `CHECK` assertions:

```cpp
#include "doctest.h"
#include "counter.h"

TEST_CASE("add increases the value") {
    Counter counter(QString("Score"), 10);
    counter.add(3);
    CHECK(counter.value() == 3);
}
```

When deciding what to test for a class, write at least three cases:

- **normal case** — the typical, expected input and outcome.
- **wrong case** — input that's invalid or out of the ordinary; does the
  class handle it sensibly?
- **edge case** — a boundary value (zero, empty, maximum, minimum) where
  off-by-one bugs like to hide.

## Troubleshooting

**CI fails with "No such file or directory" for some library header.**
The library is installed on your machine but not declared for CI. Add an
`apt-get install -y <package>` line to the dependency install step in
`.github/workflows/ci.yml`.

**Tests pass locally but fail in CI.**
Same root cause as above, generalized: something is present on your machine
(a library, a tool, a file) that isn't declared anywhere in the project, so
the CI runner doesn't have it. Check what you installed locally that isn't
in `ci.yml`.

**Build fails with "duplicate main" (or a linker error mentioning multiple
definitions of `main`).**
Either `src/main.cpp` has ended up listed under the `test_build` target in
`CMakeLists.txt`, or two test files both have
`#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN` at the top. Only one file,
ever, should have that define, and `main.cpp` belongs only to `app`.

**Asking an AI for help with a CI failure.**
Paste the *full* CI log, plus the full contents of `ci.yml` and
`CMakeLists.txt`, into the chat. Without all three, the AI is guessing at
your setup and will often suggest fixes that don't apply to this project.

## Where to see results

Push your branch or open a pull request, then check the **Actions** tab on
GitHub to see the build and test results.
