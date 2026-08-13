// Only ONE test file in the whole project may have this #define — it makes
// doctest generate a main() function, and having it in more than one file
// (or alongside src/main.cpp in the same target) causes a "duplicate main"
// link error.
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "counter.h"

// normal case: adding increases the value
TEST_CASE("add increases the value") {
    Counter counter(QString("Score"), 10);
    counter.add(3);
    CHECK(counter.value() == 3);
    CHECK(counter.name() == QString("Score"));
}

// wrong case: value never exceeds maximum
TEST_CASE("add clamps at the maximum") {
    Counter counter(QString("Score"), 10);
    counter.add(100);
    CHECK(counter.value() == 10);
}

// edge case: value never drops below zero
TEST_CASE("add clamps at zero") {
    Counter counter(QString("Score"), 10);
    counter.add(-5);
    CHECK(counter.value() == 0);
}
