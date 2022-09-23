
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
  
  int numTestCase;
    cin >> numTestCase;
    int row;
    for(int i = numTestCase; i > 0; i--) {

            int numSoldiers;
            cin >> numSoldiers;
            row = (int) (-1 + (sqrt(1+ 8 * numSoldiers))) / 2;
            cout << row << endl;

    }
    
    }