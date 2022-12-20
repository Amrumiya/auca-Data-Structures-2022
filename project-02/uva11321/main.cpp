#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

bool sortAll(int first, int second);

int M;

int main()
{
    iostream::sync_with_stdio(false);

    int N;

    while (cin >> N >> M)
    {
        if (M && N == 0)
            break;

        cout << N << " " << M << endl;
 
        vector<int> v(N);

        for (int i = 0; i < sz(v); i++)
        {
            cin >> v[i];
        }

        sort(begin(v), end(v), sortAll);

        for (int i = 0; i < sz(v); i++)
        {
            cout << v[i] << endl;
        }
    }
}

bool sortAll(int first, int second)
{
// if odd and even then  odd preciede the even
// if odd and odd then the larger odd will precide 
// if even and even then smaller will precide the larger one

    if (first % M == second % M)
    {
        if (abs(first % 2) != abs(second % 2))
            return abs(first % 2) > abs(second % 2);
        else if (abs(first % 2) == abs(second % 2) && abs(first % 2) == 1)
            return first > second;
        else if (abs(first % 2) == abs(second % 2) && first % 2 == 0)
            return first < second;
    }
    else
    {
        return first % M < second % M;
    }
}