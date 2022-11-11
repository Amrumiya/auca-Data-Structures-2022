#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int test;
    cin >> test; 
    cout<< "Lumberjacks: " << endl;
    for(int i = 0; i < test; i++) {
        vector<int> n (10);

        for(auto &e : n) cin >> e;

        for(int j = 0; j < sz(n) -1; j++) {
            if(n[j] > n[j+1]) reverse(n.begin(), n.end());

        }
        int Sort = is_sorted(n.begin(), n.end());

        cout << (Sort ==1 ? "Sorted\n" : "Unsorted\n");
    }

    




    
}