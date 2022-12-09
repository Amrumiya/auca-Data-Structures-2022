#include "../../../au/algorithm.hpp"
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Student
{
    string mName;
    double mGpa;
    Student(const string &name, double &gpa)
        : mName(name), mGpa(gpa)
    {
    }
};

struct IsEven
{
    bool operator()(int n) const
    {
        return n % 2 == 0;
    }
};

struct GreaterThan
{
    int mX;
    GreaterThan(int x) : mX(x){};

    bool operator()(int n) const
    {
        return n > mX;
    }
};

void p0101()
{
    vector<int> n = {3, 20, 100, -5, 4};
    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = auFind(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " found. Its index is " << it - begin(a) << '\n';
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }
}

void p0102()
{
    vector<int> n = {3, 20, 100, -5, 4};
    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = find(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " found. Its index is " << it - begin(a) << '\n';
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
    {
        auto it = find_if(begin(a), end(a), IsEven());
        if (it != end(a))
        {
            cout << *it << " found. Its index is " << it - begin(a) << '\n';
        }
        else
        {
            cout << " not found\n";
        }
    }
}

void p0202()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};
    auto it = auFindIf(begin(a), end(a), [](int n)
                       { return n % 2 == 0; });

    if (it != end(a))
    {
        cout << *it << " found. Its index is " << it - begin(a) << '\n';
    }
    else
    {
        cout << " No even number are found\n";
    }
}

void p03()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};

    cout << "Enter x: ";
    int x;
    cin >> x;

    auto it = find_if(begin(a), end(a), [x](auto n)
                      { return n > x; });

    if (it != end(a))
    {
        cout << *it << " found. Its index is " << it - begin(a) << '\n';
    }
    else
    {
        cout << " No even number are found\n";
    }

    auto it2 = find_if(begin(a), end(a), GreaterThan(x));

    if (it2 != end(a))
    {
        cout << *it2 << " found. Its index is " << it2 - begin(a) << '\n';
    }
    else
    {
        cout << "No even number are found\n";
    }
}

void p04()
{
    cout << "vector's size: ";
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &e : v)
        cin >> e;

    auto it = min_element(begin(v), end(v));
    if (it != end(v))
        cout << *it << " min element's index : " << it - begin(v) << endl;
    else
        cout << " min element not found " << endl;
}

struct CmpByVal
{

bool operator()(const Student &a, const Student &b) const 
{
    return a.mGpa < b.mGpa;
}

};

void p05()
{

    vector<Student> v;
    string name;
    double gpa;

    while(cin >> name >> gpa)
    {
        v.emplace_back(name, gpa);
    }

    cout << "By gpa: "<< endl;
    auto it = min_element(begin(v), begin(v), CmpByVal());

    if(it != end(v)) cout << "index : " << it - begin(v) << endl;
    else cout << "not found\n";

    cout << "By name: \n";
    auto itA = auMinElement(begin(v), end(v), [] (const Student &a, const Student &b){return a.mName < b.mName;});

    if(itA != end(v)) cout << "index: " << itA - begin(v) << endl;
    else cout << "not found\n"  ;





}


void p06()
{

    vector<Student> v;
    string name;
    double gpa;

    while(cin >> name >> gpa)
    {
        v.emplace_back(name, gpa);
    }

    sort(begin(v), end(v), [](const Student &a, const Student &b) { return a.mName < b.mName;});

    cout << fixed << showpoint << setprecision(2);
    for(const auto &e : v)
    cout << e.mName <<", " << e.mGpa << endl;

    sort(begin(v), end(v), [] (const Student &a, const Student &b){return a.mGpa < b.mGpa;});
    cout << "------------------------" << fixed << setprecision(2);

        for(const auto &e : v)
                cout << e.mName<< ", " << e.mGpa << endl; 

}

int main()
{
    iostream::sync_with_stdio(false);

    p06();
}