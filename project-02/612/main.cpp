#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct SpecialString
{
    string mStr;
    int mCnt;
    SpecialString(string str, int cnt) : mStr(str), mCnt(cnt) {}
};

int main()
{
    iostream::sync_with_stdio(false);

    int numTestCase;
    cin >> numTestCase;
    while (numTestCase--)
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

        stable_sort(begin(str), end(str), [&](SpecialString a, SpecialString b)
                                                {return a.mCnt < b.mCnt;});

        for(auto e : str)
        {
            cout << e.mStr << endl;
        }
        if(numTestCase)
        {
            cout << endl;
        }


    }
}