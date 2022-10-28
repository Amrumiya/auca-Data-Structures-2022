
#include <bits/stdc++.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../Doctest/doctest.h"

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;


TEST_CASE("back()") {

    vector<int> num1 = {1,2,3};

    REQUIRE(num1.back() == num1[sz(num1) - 1]);
}


TEST_CASE("front()") {

    vector<int> num2 = {1,2,3};

    REQUIRE(num2.front() == num2[0]);

}

TEST_CASE("pop_back()") {

    vector<int> num3 = {1, 2, 3, 4, 5};
    num3.pop_back();
    
    REQUIRE(sz(num3) == sz(num3));

}