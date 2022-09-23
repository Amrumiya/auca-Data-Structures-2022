
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);


    int numTestCase;
    cin >> numTestCase;
    int row = 1;
    int amount = 0;
    int numOfSoldiers;
    for(int i = 0; i < numTestCase; i++) {
        cin >> numOfSoldiers;

        int decrease = 1;
        //TODO
        while(numOfSoldiers != 1 || numOfSoldiers <= 0) {
            numOfSoldiers -= decrease;
            decrease++;
            amount++;

        }
        cout << row;
    }






}