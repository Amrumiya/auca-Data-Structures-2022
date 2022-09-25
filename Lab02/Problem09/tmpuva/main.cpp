
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);


    int numTestCase;
    cin >> numTestCase;

    while (numTestCase != 0) {
        int NumOfStores;
        cin >> NumOfStores;
        int minimum = 90;
        int maximum = 1;
       for(int  j = 0; j < NumOfStores; j++) {
            int NumberOfParks;
            cin >> NumberOfParks;

            minimum = min(minimum, NumberOfParks);
            maximum = max(maximum, NumberOfParks);
        }
        cout << (maximum - minimum) << "\n";
    }



}