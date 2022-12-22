#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct SpecialString
{
    string mName;
    int mValue;
    SpecialString(string name, int value) : mName(name), mValue(value) {}
};

int main()
{
    iostream::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        cin.ignore();
        int l;
        int n;
        string s;
        vector<SpecialString> str;
        cin >> l >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> s;
            int sortedness = 0;
            for (int j = 0; j < sz(s); j++)
            {
                for (int k = j + 1; k < sz(s); k++)
                {
                    if (s[j] > s[k])
                        sortedness++;
                }
            }
            str.emplace_back(SpecialString(s, sortedness));
        }
        stable_sort(begin(str), end(str), [&](SpecialString &a, SpecialString &b)
                    { return a.mValue < b.mValue; });

        for(auto e : str)
        {
            cout << e.mName << endl;
        }
        if(t)
        {
            cout << endl;
        }
    }
}