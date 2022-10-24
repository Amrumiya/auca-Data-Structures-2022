#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../Doctest/doctest.h"

//template <typename C>
//int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

#include "Rational.hpp"

TEST_CASE("Default constructor") {

    const Rational<int> x;

    REQUIRE(x.num() == 0);
    REQUIRE(x.den() == 1);

    vector<Rational<long long>> v(10);

    for(auto r : v) 
    {
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }

    ostringstream sout;
    sout << x;

    REQUIRE(sout.str() == "0/1");
}

TEST_CASE("Constructor Rational(num, den)")
{
  std::ostringstream sout;

  SUBCASE("denominator is equal to zero")
  {
    REQUIRE_THROWS_AS(Rational<int>(5,0), std::runtime_error);
  }

  SUBCASE("reducing 20/10")
  {
    Rational <int> x(20, 10);
    sout << x;
    REQUIRE(sout.str() == "2/5");
  }

    SUBCASE("reducing 11/17") {

    }





}


