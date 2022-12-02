
#include <bits/stdc++.h>
#include "../../au/algorithm.hpp"

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Student
{
    string mName;
    double mGpa;
    Student(const string &name, double gpa)
        : mName(name), mGpa(gpa)
    {
    }
};

void p0101()
{
    vector<int> n = {3, 20, 100, -5, 4};
    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = find(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }

    {
        vector<int> a = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = find(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }
}

bool isEven(int n)
{
    return n % 2 == 0;
}

struct IsEven
{
    bool operator()(int n) const
    {
        return n % 2 == 0;
    }
};

void p0102()
{
    vector<int> n = {3, 20, 100, -5, 4};
    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = auFind(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }

    {
        vector<int> a = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = auFind(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }
}

void p0201()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};

    auto it = find_if(begin(a), end(a), IsEven());
    if (it != end(a))
    {
        cout << *it << " found. Its index is " << it - begin(a) << "\n";
    }
    else
    {
        cout << " not found\n";
    }
}

void p0202()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};
    auto it = find_if(begin(a), end(a), [](int n)
                      { return n % 2 == 0; }); // lambda expression
    if (it != end(a))
    {
        cout << *it << " found. Its index is " << it - begin(a) << "\n";
    }
    else
    {
        cout << "No even number are found\n";
    }
}

struct GreaterThan
{
    int mX;
    GreaterThan(int x) : mX(x){};

    bool operator()(int n) const
    {
        return n > mX;
    }
    /* data */
};

void p03()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};

    cout << "Enter x: ";
    int x;
    cin >> x;

    auto it = find_if(begin(a), end(a),
                      [x](auto n)
                      { return n > x; });
    if (it != end(a))
    {
        cout << *it << " found. Its index is " << it - begin(a) << "\n";
    }
    else
    {
        cout << "No even number are found\n";
    }

    auto it2 = find_if(begin(a), end(a),
                       GreaterThan(x));
    if (it2 != end(a))
    {
        cout << *it2 << " found. Its index is " << it2 - begin(a) << "\n";
    }
    else
    {
        cout << "No even number are found\n";
    }
}

void p06()
{
    vector<Student> students;
    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    sort(begin(students), end(students),
         [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });
    cout << fixed << showpoint << setprecision(2);
    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }

    sort(begin(students), end(students),
         [](const Student &s1, const Student &s2)
         { return s1.mGpa > s2.mGpa; });
    cout << "------" << fixed << showpoint << setprecision(2);
    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }
}

int main()
{
    iostream::sync_with_stdio(false);

    // p0101();
    // p0102();
    // p0201();

    // p06();

    p03();
}