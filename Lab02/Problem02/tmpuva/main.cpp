
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
    int amount = 0;
    int numOfSoldiers;
    int decrease = 1;
    for(int i = 0; i < numTestCase; i++) {
        cin >> numOfSoldiers;

        while(numOfSoldiers >= 1 ) {
            if (decrease > numOfSoldiers) break;
            numOfSoldiers -= decrease;
            decrease++;
            amount++;

        }
        cout << amount << endl;
        amount = 0;
        decrease = 1;





    }
}