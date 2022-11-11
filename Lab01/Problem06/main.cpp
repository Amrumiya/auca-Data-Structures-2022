#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../Doctest/doctest.h"

#include <vector>

using namespace std;

template <typename C>
string containerToStr(const C &c)
{
    ostringstream sout;
    bool isFirst = true;
    sout << "{";
    for (const auto &e : c)
    {
        if (!isFirst)
        {
            sout << ", ";
        }
        sout << e;
        isFirst = false;
    }
    sout << "}";

    return sout.str();
}

TEST_CASE("Default constructor")
{
    vector<int> v;

    REQUIRE(v.empty());
    REQUIRE(v.size() == 0);
}

TEST_CASE("Copy Constructor")
{
    vector<int> v = {1, 2, 3, 4, 5};

    vector<int> v2 = v; // copy constructor;

    REQUIRE(v2.size() == 5);
    REQUIRE(containerToStr(v2) == "{1, 2, 3, 4, 5}");

    v[0] = 1000;
    v2[4] = 42;
    REQUIRE(containerToStr(v) == "{1000, 2, 3, 4, 5}");
    REQUIRE(containerToStr(v2) == "{1, 2, 3, 4, 42}");
}

TEST_CASE("push_back")
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    REQUIRE(v.size() == 5);
    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");
    REQUIRE(v.capacity() == 8);
}

TEST_CASE("method_back()")
{
    vector<int> v = {1, 4, 2, 7, 3};

    REQUIRE(v.back() == 3);

    v.back() = 100;

    REQUIRE(v[4] == 100);
}

TEST_CASE("method_front()")
{
    vector<int> v = {1, 3, 4, 2, 5};

    REQUIRE(v.front() == 1);

    v.front() = 90;

    REQUIRE(v[0] == 90);
}

TEST_CASE("method_pop_back")
{
    vector<int> v = {1, 2, 3, 2, 1};
    v.pop_back();

    REQUIRE(v.size() == 4);
    REQUIRE(containerToStr(v) == "{1, 2, 3, 2}");
}

TEST_CASE("method_operator[]_(index)")
{
    vector<int> v = {2, 3, 4, 6, 7};

    REQUIRE(v[0] == 2);
    REQUIRE(v[4] == 7);
    // REQUIRE(v[5] == 3);
}

TEST_CASE("method_at")
{
    vector<int> v = {1, 2, 3, 4, 5};

    REQUIRE(v.at(0) == 1);
    REQUIRE(v.at(4) == 5);
    REQUIRE_THROWS_AS(v.at(5), out_of_range);
}

TEST_CASE("operator = ")
{
    vector<int> v = {1, 2, 3, 4};
    vector<int> v2 = {5, 6, 7, 8, 9};

    v = v2;
    v2 = vector<int>();

    REQUIRE(containerToStr(v) == "{5, 6, 7, 8, 9}");
    REQUIRE(containerToStr(v2) == "{}");
    REQUIRE(v2.size() == 0);
    REQUIRE(v.size() == 5);
}

// TEST_CASE("auto element : container")
// {
//     vector<int> v = {1, 2, 3, 4, 5};

//     for (auto &c : v)
//     {
//         c *= 10;
//         REQUIRE(containerToStr(c) == "{10, 20, 30, 40, 50}");
//     }
// }

TEST_CASE("iterators")
{
    SUBCASE("*it")
    {
        vector<int> v = {1, 2, 3, 4, 5};
        auto it = v.begin();
        auto it1 = v.end() - 1;

        REQUIRE(*it == 1);
        REQUIRE(*it1 == 5);
    }

    SUBCASE("++it")
    {
        vector<int> v = {2, 4, 6, 8};
        auto it = v.begin();
        ++it;
        REQUIRE(*it == 4);
        ++it;
        REQUIRE(*it == 6);
    }

    SUBCASE("--it")
    {
        vector<int> v = {1, 3, 5, 7, 9};
        vector<int>::iterator it = v.end() - 1;

        --it;
        REQUIRE(*it == 7);

        --it;
        REQUIRE(*it == 5);
    }

    SUBCASE("it += n")
    {
        vector<int> v = {10, 20, 30, 40, 50};
        auto it = v.begin();

        it += 2;
        REQUIRE(*it == 30);

        it += 2;
        REQUIRE(*it == 50);
    }

    SUBCASE("it -= n")
    {
        vector<int> v = {60, 70, 80, 90};
        auto it = v.end() - 1;

        it -= 2;
        REQUIRE(*it == 70);

        it -= 1;
        REQUIRE(*it == 60);
    }

    SUBCASE("it2 - it1")
    {
        vector<int> v = {1, 2, 3, 4, 5};
        auto it1 = v.begin();
        auto it2 = v.end() - 1;

        REQUIRE((it2 - it1) == 4);

        auto it3 = it1 + 2;
        REQUIRE((it2 - it3) == 2);
    }
}

TEST_CASE("methods insert")
{
    SUBCASE("insert(it, value")
    {
        vector<int> v = {1, 2, 3, 4, 5};
        auto it = v.begin();
        v.insert(it, 8);
        v.insert(v.end(), 10);

        // it = v.insert(v.begin() + 2, 9);

        REQUIRE(containerToStr(v) == "{8, 1, 2, 3, 4, 5, 10}");
    }
    SUBCASE("insert(it, begin, end)")
    {
    }
}

TEST_CASE("methods erase")
{
    SUBCASE("erase(it)")
    {
        vector<int> v = {1, 3, 5, 7, 9};
        auto it = v.begin() + 3;
        v.erase(it);
        REQUIRE(containerToStr(v) == "{1, 3, 5, 9}");

        it = v.begin() + 1;
        v.erase(it);
        REQUIRE(containerToStr(v) == "{1, 5, 9}");
    }

    SUBCASE("erase(beg, end)")
    {
        vector<int> v = {2, 4, 6, 8};
        v.erase(v.begin() + 1, v.end());
        REQUIRE(containerToStr(v) == "{2}");
    }
}

TEST_CASE("constructor vector")
{
    vector<int> v(3, 10);
    vector<int> v1(v.begin(), v.end());
    REQUIRE(containerToStr(v1) == "{10, 10, 10}");

    vector<int> v2(v1.begin() + 2, v1.end());
    REQUIRE(containerToStr(v2) == "{10}");
}

TEST_CASE("reverse")
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    reverse(v.begin(), v.end());
    REQUIRE(containerToStr(v) == "{6, 5, 4, 3, 2, 1}");
}

TEST_CASE("sort")
{
    vector<int> v = {2, 1, 5, 6, 3, 4};
    sort(v.begin(), v.end());
    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5, 6}");
}

TEST_CASE("binary search")
{
    vector<int> v = {10, 15, 20, 25, 30, 35, 40};
    REQUIRE(binary_search(v.begin(), v.end(), 30) == true);
    REQUIRE(binary_search(v.begin(), v.end(), 60) == false);
}

TEST_CASE("min_element")
{
    vector<int> v = {54, 23, 45, 78, 12, 18};
    REQUIRE(*min_element(v.begin(), v.end()) == 12);
}

TEST_CASE("max_element")
{
    vector<int> v = {54, 23, 45, 78, 12, 18};
    REQUIRE(*max_element(v.begin(), v.end()) == 78);
}