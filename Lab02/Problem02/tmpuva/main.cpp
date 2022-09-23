
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
 int numTestCase;
    cin >> numTestCase;
    //int row = 1;
    int amount[] = {0,0,0,0,0,0};
    int numOfSoldiers;
    int decrease = 1;
    int Arr[6];
    for(int i = 0; i < numTestCase; i++) {
        cin >> numOfSoldiers;
        Arr[i] = numOfSoldiers;
    }

    for(int i = 0; i < 6; i++) {
        if (i == 7) break;
        while (Arr[i] >= 1) {
            if (decrease > Arr[i]) break;
            Arr[i] -= decrease;
            decrease++;
            amount[i]++;

        }
        decrease = 1;
    }
    for(int i : amount)
        cout << i << endl;



    }