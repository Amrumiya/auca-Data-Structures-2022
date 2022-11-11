
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    
    int test;
    cin >> test;
    for(int i =0; i < test; i++)  
    {
        int store;
        cin>> store;

    int min = 90;
    int max = -1;
    for( int j = 0; j < store; j++) {
        int parks;
        cin >> parks;

        min = (min < parks) ? min = min : min = parks;
        max = ( max > parks)? max = max : max = parks;

    }
        cout << (max - min) * 2<< endl;


    }
    
    




}