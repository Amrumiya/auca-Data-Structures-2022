#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../Doctest/doctest.h"

#include "BigInt.hpp"

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;


TEST_CASE("Default constructor")
{
    BigInt x;

    ostringstream sout;
    sout << x;
  
    REQUIRE(sout.str() == "0");

    vector<BigInt> v(5);
    for(const auto &e : v)
    {
        ostringstream sout2;
        sout2 << e;
        REQUIRE(sout2.str() == "0");

    }
}

TEST_CASE("Constructor with string")
{
    ostringstream sout;
    SUBCASE("Positive number") 
    {
    BigInt x("123456789123456789");
    sout << x;
    REQUIRE(sout.str() == "123456789123456789" );
    }
    SUBCASE("Negative number")
    {
        BigInt x("-123");
        sout << x;
        REQUIRE(sout.str() == "-123");
    }
    SUBCASE("Empty string")
    {
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }
    SUBCASE("+0")
    {
        BigInt x("0+");
        sout << x;

        REQUIRE(sout.str() == "0");
    }
    SUBCASE("Case -0")
    {
        BigInt x("-0");
        sout << x;

        REQUIRE(sout.str() == "0");
    }
    SUBCASE("Case 3")
    {
       REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
    }
    SUBCASE("+")
    {
        REQUIRE_THROWS_AS(BigInt("+"), runtime_error);
    }
    SUBCASE("-")
    {
        REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
    }
}






