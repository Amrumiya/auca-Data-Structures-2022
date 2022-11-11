#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int search(vector<int> num) {

int sum = 1;

for(int i = 0; i < sz(num); i++) {

    if(num[i] > sum) sum = num[i];
    
    }

 return sum;

}

int main() {

    int test;
    cin >> test;
    for(int i = 1;  i <= test; i++) {
        vector<string> msg(10);
        vector<int> rank(10);

        for(int j = 0; j < sz(msg); j++) {
            cin >> msg[j];
            cin >> rank[j];
        }
    int Search = search(rank);

    cout << "Case #" <<i << endl; 
    for(int k = 0; k < sz(rank); k++) {
        if(Search == rank[k])
        cout << msg[k] << endl;
    }


    }
}
    


