
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);


    int numTestCase;
    cin >> numTestCase;
    for (int i = 0; i < numTestCase; i++) {
        // int total[2];
        int total;
        int Num;
        cin >> Num;
        //int j = 0;
        total = (((((Num * 567) / 9) + 7492) * 235) / 47) - 498;
        // j++;
        string toString = to_string(total);
        int length = toString.length();
        //cout << toString.substr(length - 2, 0, length - 1,length);
         //cout << toString[length - 2];
        printf("%c\n", toString[length - 2]);
    }



}