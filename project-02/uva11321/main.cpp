#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

bool sortAll(int first, int second);

int main()
{
    iostream::sync_with_stdio(false);

    int N;
    int M;
    while (cin >> N >> M)
    {

        vector<int> v(N, 0);
        if (M && N == 0)
        {
            cout << N << " " << M << endl;
            break;
        }

        for (auto &e : v)
            cin >> e;

        sort(begin(v), end(v), [&](const int a, const int b)
             {
                 if (a % M == b % M)
                 {
                     if (abs(a) % 2 == abs(b) % 2)
                     {
                         if (abs(a) % 2 == 1)
                             return a > b;
                         else
                             return b > a;
                     }
                     else 
                     {
                        return abs(a) % 2 == 1;
                     }
                 }
                 else
                 {
                    return a % M < b % M;
                 }
             });

            cout << N << " " << M << endl;

        for(auto &e : v)
        {
            cout << e << "\n";
        }
    }
}