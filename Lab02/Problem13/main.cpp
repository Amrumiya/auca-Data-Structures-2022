
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    
    int a;
    int b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
        {
            break;
        }
        else
        {
            vector<int> money;
            for (int i = 0; i < a; i++)
            {
                int m;
                cin >> m;
                money.push_back(m);
            }
            for (int i = 0; i < b; i++)
            {
                int debBank, credBank, value;
                cin >> debBank >> credBank >> value;
                money[credBank - 1] += value;
                money[debBank - 1] -= value;
            }
            bool possible = true;
            for (int i = 0; i < a; i++)
            {
                if (money[i] < 0)
                {
                    possible = false;
                }
            }

            cout << (possible ? "S\n" : "N\n");
        }
    }
}