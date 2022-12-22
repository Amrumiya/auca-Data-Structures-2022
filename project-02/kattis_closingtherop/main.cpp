#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{

  int numTestCase;
  cin >> numTestCase;
  for(int j = 1; j <= numTestCase;j++)
  {
    int numTest;
    cin >> numTest;
    vector<int> a, b;
    for(int i = 0; i < numTest; i++)
    {
        int num;
        char s;
        cin >> num >> s;
        num--;

        if(s == 'B') b.push_back(num);
        else a.push_back(num);
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int ans = 0;

    int acR = accumulate(begin(a), begin(a) + min(sz(a), sz(b)), 0);
    int acB = accumulate(begin(b), begin(b) + min(sz(a), sz(b)), 0);

    ans = acR + acB;
    cout << "Case #" << j << ": ";
    cout << ans << endl;


  }
}