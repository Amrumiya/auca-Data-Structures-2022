#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

   int NumTestCase;
    cin >> NumTestCase;
    int increment = 0;
    while(increment < NumTestCase) {
        int NumOfStores;
        cin >> NumOfStores;
        int Minimum = 90;
        int Maximum = -1;
        for (int j = 0; j < NumOfStores; ++j) {
            int NumOfParks;
            cin >> NumOfParks;

            Minimum = (Minimum < NumOfParks) ? Minimum = Minimum : Minimum = NumOfParks;
            Maximum = (NumOfParks > Maximum) ? Maximum = NumOfParks : Maximum = Maximum;
        }
        cout << (Maximum - Minimum) * 2 << '\n';
        increment++;
    }
}