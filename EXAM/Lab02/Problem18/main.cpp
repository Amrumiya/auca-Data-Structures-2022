#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Student
{
    string mName;
    double mGpa;
    Student(string &name, double &gpa) : mName(name), mGpa(gpa){};
};

template <typename ForwardIter, typename Key>
ForwardIter auFind(ForwardIter beg, ForwardIter end, const Key &key)
{
    for (; beg != end; beg++)
    {
        if (*beg == key)
        {
            return beg;
        }
    }
    return beg;
}

template <typename ForwardIter, typename Key>
ForwardIter auFindIf(ForwardIter beg, ForwardIter end, Key pread)
{
    for (; beg != end; beg++)
    {
        if (pread(*beg))
            return beg;
    }
    return beg;
}

template <typename Iter, typename Comp>
Iter auMinElement(Iter beg, Iter end, Comp comp)
{
    Iter min = beg;
    while (beg != end)
    {
        if (comp(*beg, *min))
        {
            min = beg;
        }
        beg++;
    }
    return min;
}

struct IsEven
{

    bool operator()(int x) const
    {
        return x % 2 == 0;
    }
};

struct GreaterThan
{

    int mX;
    GreaterThan(int &x) : mX(x){};

    bool operator()(int n)
    {

        return n > mX;
    }
};

struct CmpByVal
{
    bool operator()(const Student &a, const Student &b)
    {
        return a.mGpa < b.mGpa;
    }
};

void p06()
{
     vector<int> v = {0, 4, 5, 10, 12, 20, 25, 40};

    






}

int main()
{
    iostream::sync_with_stdio(false);

    p06();
}