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

template<typename ForwardsIter, typename Key>
ForwardsIter auFind(ForwardsIter beg, ForwardsIter end, const Key &key )
{
    while(beg != end)
    {
        if(*beg == key)
        return beg;
    }
    return beg;
}

template<typename ForwardIter, typename UnaryPredicate>
ForwardIter auFindIf(ForwardIter beg, ForwardIter end, UnaryPredicate pread)
{
    for(; beg != end; ++beg)
    {
        if(pread(*beg))
        {
            return beg;
        }
    }
    return beg;
}

template<typename Iter>
Iter auMinElement(Iter beg, Iter end)
{
    if(beg == end) return end;

    Iter min = beg++;
    
    while(beg != end)
    {
        if(*beg < *min)
        min = beg;

        beg++;
    }
    return min;


}


void p06()
{

 vector<int> v = {0, 0, 4, 5, 10, 10, 10, 12, 20, 25, 35, 25,
25, 40};

for(int x; cin >> x;)

{
    auto it = equal_range(begin(v), end(v), x);

    if(it.first == it.second) cout << " there are not elements equalt to " << x<< endl;
    else cout << " number of elements equal to " << x << " are " << it.second - it.first<< endl;
}

 

}

template <typename Iter>
Iter auMinElement(Iter beg, Iter end)
{
    if (beg == end)
        return end;

    Iter min = beg++;

    while (beg != end)
    {
        if (*beg < *min)
        {
            min = beg;
        }
        beg++;
    }
    return min;
}

int main()
{
    iostream::sync_with_stdio(false);

    p06();
}