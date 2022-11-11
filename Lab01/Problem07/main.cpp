#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../Doctest/doctest.h"

#include <string>

using namespace std;

TEST_CASE("default_constructor")
{
    string str;
    REQUIRE(str.empty());
    REQUIRE(str.length() == 0);
}

TEST_CASE("constructor_with_size_and_initial_value")
{
    string str = "Hello";
    string str1("World");

    REQUIRE(str == "Hello");
    REQUIRE(str1.length() == 5);
}

TEST_CASE("copy_constructor")
{
    string str = "JAVA";
    string str1 = str;

    REQUIRE(str1 == "JAVA");

    str1.append(str);

    REQUIRE(str1 == "JAVAJAVA");
}

TEST_CASE("move_constructor")
{
    string str("AUCA");
    string str1(move(str));
    REQUIRE(str1 == "AUCA");
    REQUIRE(str.empty());
}

TEST_CASE("move_assignment")
{
    string str("AUCA");
    string str1;

    str1 = (move(str));

    REQUIRE(str1 == "AUCA");
    REQUIRE(str.empty());
}

TEST_CASE("subscript_operator")
{
    char str[] = "hello";
    REQUIRE(str[0] == 'h');
    REQUIRE(sizeof(str) == 6);
    // REQUIRE(str[6] == '\0');
}

TEST_CASE("method_at")
{
    string str("cplusplus");
    REQUIRE(str.at(1) == 'p');
    REQUIRE(str.at(8) == 's');
    REQUIRE_THROWS_AS(str.at(9), out_of_range);
}

TEST_CASE("push_back")
{
    string str("Hello");

    str.push_back(' ');
    str.push_back('W');
    str.push_back('o');
    str.push_back('r');
    str.push_back('l');
    str.push_back('d');

    REQUIRE(str == "Hello World");
}

TEST_CASE("pop_back")
{
    string str("Hello World");

    str.pop_back();
    str.pop_back();
    str.pop_back();
    str.pop_back();
    str.pop_back();
    str.pop_back();

    REQUIRE(str == "Hello");
}

TEST_CASE("+, += operators")
{
    SUBCASE("+")
    {
        string str("Hello");
        string str1(" World");

        string str2 = str + str1;

        REQUIRE(str2 == "Hello World");
    }

    SUBCASE("+=")
    {
        string str("Hello");
        str += " World";
        REQUIRE(str == "Hello World");
    }
}

TEST_CASE("==, !=, <")
{
    SUBCASE("==")
    {
        string str("Python");
        string str1("Python");
        REQUIRE((str == str1) == true);
    }

    SUBCASE("!=")
    {
        string str("Python");
        string str1("python");
        REQUIRE((str != str1) == true);
    }

    SUBCASE("<")
    {
        string str("Python");
        string str1("python1");
        REQUIRE((str < str1) == true);
    }
}

TEST_CASE("methods front(), back()")
{
    SUBCASE("front()")
    {
        string str("Google");
        str.front() = '!';
        REQUIRE(str.front() == '!');
        REQUIRE(str == "!oogle");
    }

    SUBCASE("back()")
    {
        string str("C#");
        str.back() = '+';
        REQUIRE(str == "C+");
    }
}

TEST_CASE("methods substr(), find()")
{
    string str("Hello World");

    REQUIRE(str.substr(6, 5) == "World");
    REQUIRE(str.find('W') == 6);
}

TEST_CASE("iterators")
{
    SUBCASE("*it")
    {
        string str("PROGRAMMING");
        auto it = str.begin();
        auto it1 = str.end() - 1;
        REQUIRE(*it == 'P');
        REQUIRE(*it1 == 'G');
    }

    SUBCASE("++it")
    {
        string str("PROGRAMMER");
        auto it = str.begin();
        ++it;
        REQUIRE(*it == 'R');
        ++it;
        REQUIRE(*it == 'O');
    }

    SUBCASE("--it")
    {
        string str("PROGRAMMER");
        auto it = str.end() - 1;
        --it;
        REQUIRE(*it == 'E');
        --it;
        REQUIRE(*it == 'M');
    }

    SUBCASE("it += n")
    {
        string str("PROGRAMMER");
        auto it = str.begin();
        it += 3;
        REQUIRE(*it == 'G');
        it += 2;
        REQUIRE(*it == 'A');
    }

    SUBCASE("it -= n")
    {
        string str("PROGRAMMER");
        auto it = str.end() - 1;
        it -= 4;
        REQUIRE(*it == 'A');
        it -= 5;
        REQUIRE(*it == 'P');
    }

    SUBCASE("it2 - it1")
    {
        string str("PROGRAMMING");
        auto it = str.begin();
        auto it1 = str.end() - 1;
        REQUIRE((it1 - it) == 10);
    }
}

TEST_CASE("insert")
{
    string str("C++ C#");
    str.insert(3, 1, ',');
    REQUIRE(str == "C++, C#");
}

TEST_CASE("erase")
{
    string str("C++, C#, JAVA");
    str.erase(7, 6);
    REQUIRE(str == "C++, C#");
}

TEST_CASE("constructor string")
{
    string str("ASSAMBLER");
    string str1(str.begin(), str.end());
    REQUIRE(str1 == "ASSAMBLER");
}

TEST_CASE("reverse")
{
    string str("GOOGLE");
    reverse(str.begin(), str.end());
    REQUIRE(str == "ELGOOG");
}

TEST_CASE("sort")
{
    string str("cbda");
    sort(str.begin(), str.end());
    REQUIRE(str == "abcd");
}

TEST_CASE("binary_search")
{
    string str = "Apple";
    REQUIRE(binary_search(str.begin(), str.end(), 'A'));
}