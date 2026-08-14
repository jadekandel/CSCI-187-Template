// Only ONE test file in the whole project may have this #define — it makes
// doctest generate a main() function, and having it in more than one file
// (or alongside src/main.cpp in the same target) causes a "duplicate main"
// link error.
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "prime.h"

// normal case: a typical prime number is identified correctly
TEST_CASE("isPrime returns true for a prime number") {
    CHECK(isPrime(7) == true);
}

// wrong case: a typical non-prime (composite) number is rejected
TEST_CASE("isPrime returns false for a composite number") {
    CHECK(isPrime(9) == false);
}

// edge case: boundary values (negative, zero, one, smallest prime)
TEST_CASE("isPrime handles boundary values") {
    CHECK(isPrime(-1) == false);
    CHECK(isPrime(0) == false);
    CHECK(isPrime(1) == false);
    CHECK(isPrime(2) == true);
}
