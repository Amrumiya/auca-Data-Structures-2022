
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    int numTestCase;
    cin >> numTestCase;
    for(int i = 0; i < numTestCase; i++ ) {
        int a, b;
        cin >> a >> b;
        int total = (a / 3) * (b / 3);
        cout << total<< '\n';

    }


}