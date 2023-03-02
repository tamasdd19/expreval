#include <catch.hpp>
#include "../include/expreval.h"

using namespace expreval;

TEST_CASE("No operations")
{
    REQUIRE(evaluate("0") == 0.f);
    REQUIRE(evaluate("2") == 2.f);
    REQUIRE(evaluate("-2") == -2.f);
    REQUIRE(evaluate("(2)") == 2.f);
    REQUIRE(evaluate("(-2)") == -2.f);
    REQUIRE((evaluate("-(2)") == -2.f) == false); // unary - is not allowed in this case
    // unary - is only allowed at the beginning of the expression or at the beginning of parantheses, as a prefix to a number!
}

TEST_CASE("Simple operations")
{
    REQUIRE(evaluate("1+1") == 2.f);
    REQUIRE(evaluate("10-10") == 0.f);
    REQUIRE(evaluate("100-90+20") == 30.f);
    REQUIRE(evaluate("1.5+2.5") == 4.f);
    REQUIRE(evaluate("-2*8") == -16.f);
    REQUIRE(evaluate("-90/2+2") == -43.f);
}

TEST_CASE("Complex operations")
{

}

TEST_CASE("Random operations with spaces")
{
    REQUIRE(evaluate(" 1   +  2 ") == 3.f);
    REQUIRE(evaluate("2 * 4 / 8") == 1.f);
}