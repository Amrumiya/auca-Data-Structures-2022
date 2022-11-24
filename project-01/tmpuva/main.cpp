#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../Doctest/doctest.h"

#include "BigInt.hpp"

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
/*
TEST_CASE("Default constructor")
{
    BigInt x;

    ostringstream sout;
    sout << x;

    REQUIRE(sout.str() == "0");

    vector<BigInt> v(5);
    for (const auto &e : v)
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
        REQUIRE(sout.str() == "123456789123456789");
    }
    SUBCASE("Negative number")
    {
        BigInt x("-123");
        sout << x;
        REQUIRE(sout.str() == "-123");
    }
    SUBCASE("+123")
    {
        BigInt x("+123");
        sout << x;
        REQUIRE(sout.str() == "123");
    }

    SUBCASE("Empty string")
    {
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }
    SUBCASE("+0")
    {
        BigInt x("+0");
        sout << x;

        REQUIRE(sout.str() == "0");
    }
    SUBCASE("Case -0")
    {
        BigInt x("-0");
        sout << x;

        REQUIRE(sout.str() == "0");
    }
    SUBCASE("+")
    {
        REQUIRE_THROWS_AS(BigInt("+"), runtime_error);
    }
    SUBCASE("-")
    {
        REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
    }
    SUBCASE("Wrong number")
    {
        REQUIRE_THROWS_AS(BigInt("1234sd12"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("1234--12"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("1234sdw12"), runtime_error);

    }
}
TEST_CASE("Checking number with sign")
{
    SUBCASE("positive and positive")
    {
        BigInt x("+123");
        BigInt y("+00000123");

        REQUIRE(x == y);
    }
    SUBCASE("negative and positive")
    {
        BigInt x("-123");
        BigInt y("+00000123");

        REQUIRE(x != y);
    }
    SUBCASE("positive and negative ")
    {
        BigInt x("+123");
        BigInt y("-00000123");

        REQUIRE(x != y);
    }
    SUBCASE("negative and negative")
    {
        BigInt x("-123");
        BigInt y("-00000123");

        REQUIRE(x == y);
    }
}


TEST_CASE("Greater or Equal")
{
    ostringstream sout;
    SUBCASE("-10 and -10")
    {
        BigInt x("-10");
        BigInt y("-10");

        REQUIRE(x >= y);
    }
    SUBCASE("-10 and 10")
    {
        BigInt x("10");
        BigInt y("-10");

        REQUIRE(x >= y);
    }
}

TEST_CASE("Less than or equal ")
{
    ostringstream sout;
    SUBCASE("-100 and 100")
    {
        BigInt x("100");
        BigInt y("-100");

        REQUIRE(y <= x);
    }
    SUBCASE("-5 and 4")
    {
        BigInt x("-5");
        BigInt y("4");

        REQUIRE(x <= y);
    }
}

TEST_CASE("Less")
{
    ostringstream sout;

    SUBCASE(" -1 and 2")
    {
        BigInt x("-1");
        BigInt y("2");

        REQUIRE(x < y);
    }
}

TEST_CASE("Greater")
{
    ostringstream sout;

    SUBCASE("1 and 2")
    {
        BigInt x("1");
        BigInt y("2");

        REQUIRE(y > x);
    }
}
*/

TEST_CASE("postive and positive, test #3")
{
    ostringstream sout;
    for(int x = 0; x <= 1000; x++)
    {
        for(int y = 0; y <= 1000; y++)
        {
            BigInt a(to_string(x));
            BigInt b(to_string(y));
            sout << a + b;

            REQUIRE(sout.str() == to_string(x + y));
            sout.str("");
        }
    }
}

/*
TEST_CASE("Subtraction")
{
    SUBCASE("positive-negative")
    {
        BigInt x1(3);
        BigInt y1(-2);
        REQUIRE(x1 - y1 = 5);

        for(int x2 = 0; x2 <= 100; ++x2)
        {
            for(int y2 = -100; y2 < 0; ++y2)
            {
                BigInt a(x2);
                BigInt b(y2);
                REQUIRE(a - b == x2 - y2);
            }
        }
    }
    SUBCASE("negative-positive")
    {
        BigInt x1(-3);
        BigInt y1(2);
        REQUIRE(x1 - y1 = -5);

        for(int x2 = -100; x2 <= 0; ++x2)
        {
            for(int y2 = 0; y2 < 100; ++y2)
            {
                BigInt a(x2);
                BigInt b(y2);
                REQUIRE(a - b == x2 - y2);
            }
        }
    }
    SUBCASE("poistive-positive ")
    {
        BigInt x1(1024);
        BigInt y1(526);
        REQUIRE(x1 - y1 == 1024 - 526);

    //    BigInt x2(526);
      //  BigInt y2(1024);
    

    }
}
*/