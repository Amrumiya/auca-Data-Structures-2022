#include <iostream>
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
  
     int testCases;
    cin >> testCases;
    while (testCases--)
    {
        long n;
        cin >> n;
        cout << (long)(-1 + (sqrt(1 + 8 * n))) / 2 << endl;
    }
}