
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int test;
    cin >> test;
    for(int i = 1; i <= test; i++) {
        int walls;
        cin>> walls;
        vector<int> n (walls);
        for(int j = 0; j < sz(n); j++) {
            cin >> n[j];
        }
        int high = 0; int low = 0;
        for(int j = 0;  j< sz(n) - 1; j ++) {
            if(n[j] > n[j + 1]) low++;
            if(n[j] < n[j + 1]) high++;
            
        }
        cout << "Case " << i << ": " << high <<" " << low << endl;
    }
    


}