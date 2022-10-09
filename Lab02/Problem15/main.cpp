
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int Search(vector<int> num) {
    int max = 1;
    for (int i = 0; i < (int) num.size(); i++) {
        if (num[i] > max) max = num[i];
    }
    return max;
}


int main()
{
    iostream::sync_with_stdio(false);
  int numTestCase;
    cin >> numTestCase;

    for (int i = 1; i <= numTestCase; i++) {

        vector<string> text(10);
        vector<int> rank(10);
        for (int j = 0; j < 10; j++) {
            cin >> text[j];
            cin >> rank[j];
        }

        int max = Search(rank);

        cout << "Case #" << i << ":" <<  endl;
        for (int k = 0; k < sz(rank); k++) {
            if (rank[k] == max)
                cout << text[k] << '\n';
        }
    }
}