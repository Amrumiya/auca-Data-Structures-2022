#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;


int main()
{

 int n;
 cin >> n;
 vector<pair<int, string>> cups;
  cups.resize(n);

  for(int i = 0; i < n; i++)
  {
    string rad;
    string diam;

    cin >> rad >> diam;

    int a;
    if(isdigit(rad[0]))
    {
      a = stoi(rad);
      a/=2;
      cups.push_back(make_pair(a, diam));
    }
    else 
    {
      a = stoi(diam);
      cups.push_back(make_pair(a, rad));
    }

  }
sort(begin(cups), end(cups), [](const pair<int,string> &l, const pair<int, string> &r){
  return l.first > r.first;
});

for(int i = n - 1; i >= 0; i--)
{
  cout << cups[i].second << endl;
}
  
  
}