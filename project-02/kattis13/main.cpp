
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    vector<string> v;
    for (string text; getline(cin, text);)
    {
        v.emplace_back(text);

        sort(begin(v), end(v), [](const string &a, const string &b)
             { return a < b; });

        reverse(begin(v), end(v));

        for (auto &e : v)
        {
            cout << e << endl;
        }
    }
}