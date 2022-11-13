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








