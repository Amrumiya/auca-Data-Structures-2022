
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    
   int numTestCase;
   string line;
   cin >> numTestCase;
    for(int i = 0; i < numTestCase; i ++) {
        getline(cin,line);

        istringstream sinp(line);
        int countM = 0;
        int countF = 0;
        int cnt = 0;

        for (string l; sinp >> l;)
        {

            countM += l[0] == 'M';
            countM += l[1] == 'M';

            countF += l[0] == 'F';
            countF += l[1] == 'F';
            cnt++;
        }

        cout << (cnt > 1 && countF == countM ? "LOOP\n" : "NO LOOP\n");
    }
}