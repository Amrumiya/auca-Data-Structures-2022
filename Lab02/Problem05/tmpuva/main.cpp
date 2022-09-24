
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

 int numOfRoads, Integers, reminder;
    for (int i = 1; cin >> numOfRoads >> Integers;) {
        if ((numOfRoads && Integers) == 0) break;
        if (numOfRoads % 2 != 0 || Integers % 2 != 0) {
         reminder = numOfRoads % Integers;
    }
    else {
        reminder = numOfRoads / Integers;
    }
    if (reminder > 27) {
        cout << "Case " << i << ": " << "impossible" << endl;
        i++;
    }
   else if (reminder <= numOfRoads) {
        cout << "Case " << i << ": " << 1 << endl;
        i++;
    }

}




}