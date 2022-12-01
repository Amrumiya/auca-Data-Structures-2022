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

TEST_CASE("Equal")
{
    SUBCASE("two nums")
    {
    BigInt x("2");
    BigInt y("2");

    REQUIRE( x == y);
    }
    SUBCASE("3 and 3")
    {
        BigInt x("3");
        BigInt y("3");

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


TEST_CASE("BigInt with long long")
{
    ostringstream sout;
    SUBCASE("-9223372036775808")
    {
        BigInt x(numeric_limits<long long>::min());
        sout << x;
        REQUIRE(sout.str() == "-9223372036854775808");
    }
}

TEST_CASE("Long long parameter (constructor)")
{
    ostringstream sout;
    for(int i = -1000; i <= 1000; i++)
    {
        BigInt x(i);
        sout << x;
        REQUIRE(sout.str() == to_string(i));
        sout.str("");
    }
}
TEST_CASE("Adding")
{
    ostringstream sout;
    SUBCASE("postive and positive, test #3")
    {
        BigInt x("999");
        BigInt y("1");
        sout << x + y;
        REQUIRE(sout.str() == "1000");
    }
    SUBCASE("positive and positive, test #1")
    {
        BigInt x("193");
        BigInt y("59");
        sout << x + y;
        REQUIRE(sout.str() == "252");
    }
    
SUBCASE("positive and positive, test #2")
{
    for (int x = 0; x <= 1000; x++)
    {
        for (int y = 0; y <= 1000; y++)
        {
            BigInt a(to_string(x));
            BigInt b(to_string(y));
            sout << a + b;
            REQUIRE(sout.str() == to_string(x + y));
            sout.str("");
        }
    }
} 
SUBCASE("negative and positive")
{
    BigInt x("-5");
    BigInt y("4");
    sout << x + y;
    REQUIRE(sout.str() == "-1");
}
SUBCASE("positive and negative")
{
    BigInt x("5");
    BigInt y("-2");
    sout << x + y;
    REQUIRE(sout.str() == "3");

    }
}

TEST_CASE("input operator")
{
    ostringstream sout;
    SUBCASE("correct input #1")
    {
        istringstream sinp("123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == 123);
    }

    SUBCASE("correct input #2")
    {
        istringstream sinp("  123 ");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.good());
        REQUIRE(x == 123);
    }

    SUBCASE("correct input #3")
    {
        istringstream sinp("123x103");
        int x;
        char ch;
        sinp >> x >> ch;
        REQUIRE(sinp.good());
        REQUIRE(x == 123);
        REQUIRE(ch == 'x');
    }

    SUBCASE("correct input #4")
    {
        istringstream sinp(" +123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == 123);
    }

    SUBCASE("correct input #5")
    {
        istringstream sinp(" -123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == -123);
    }
}

TEST_CASE("subtraction")
{
    SUBCASE("positive and negative")
    {
        BigInt x1(3);
        BigInt y1(-2);
        REQUIRE(x1 - y1 == 5);

        for(int x2 = 0; x2 <= 100; x2++)
        {
            for(int y2 = -100; y2 < 0; y2++)
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
        REQUIRE(x1 - y1 == -5);

        for(int x2 = -100; x2 < 0; x2++)
        {
            for(int y2 = 0; y2 <= 100; y2++)
            {
                BigInt a(x2);
                BigInt b(y2);
                REQUIRE(a - b == x2 - y2);
            }
        }
    }
    SUBCASE("positive - positive")
    {
        BigInt x1(1024);
        BigInt y1(526);
        REQUIRE(x1 = y1 == 1024 - 526);

        BigInt x2(2024);
        BigInt y2(526);
        REQUIRE(x2 - y2 == 2024 - 526);

        BigInt x3(10000);
        BigInt y3(1);
        REQUIRE(x3 - y3 == 10000 - 1);
    }
}