#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../Doctest/doctest.h"

#include <sstream>
#include <vector>

#include "Rational.hpp"

using namespace std;

TEST_CASE("Default constructor")
{
    const Rational<int> x;

    REQUIRE(x.num() == 0);
    REQUIRE(x.den() == 1);

    vector<Rational<long long>> v(10);

    for (auto r : v)
    {
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }

    ostringstream sout;
    sout << x;

    REQUIRE(sout.str() == "0/1");
}

