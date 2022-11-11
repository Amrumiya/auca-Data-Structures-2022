#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int numTestCase;
    cin >> numTestCase;
    for(int i = 0; i < numTestCase; i++) {
        vector<int> Arr(3);
            cin >> Arr[0];
            cin >> Arr[1];
            cin >> Arr[2];
        
        sort(Arr.begin(), Arr.end());
        cout << Arr[1] << '\n'; 
    }


    


}