
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int test;
    cin >> test;
    for(int i = 0; i < test; i++) {
    int n;
    cin >> n;
    n = (((((n * 567) / 9) + 7492)*235)/47)-498;
    string txt = to_string(n);
    int length = txt.size() - 2;

    cout << txt[length] << '\n';
}











}