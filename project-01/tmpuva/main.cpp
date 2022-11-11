#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../Doctest/doctest.h"

#include "BigInt.hpp"

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;


TEST_CASE("Default constructor")
{
    BigInt a;

    ostringstream sout;
    sout << a;
  
    REQUIRE(sout.str() == "0");
}








