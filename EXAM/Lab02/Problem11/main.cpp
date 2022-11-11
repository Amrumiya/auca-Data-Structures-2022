#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int love(string s) {
    int sum = 0;
    for(int i = 0; i < sz(s); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') 
            sum+= s[i] - 'a' + 1;
        if(s[i] >= 'A' && s[i] <= 'Z') 
        sum += s[i] - 'A' +1;
    }

    if(sum % 9 == 0) return 9;
    else return sum % 9;



}


int main()
{
    iostream::sync_with_stdio(false);

    string a, b;
    while(getline(cin, a) && getline(cin, b)) {
        int s1 = love(a), s2 = love(b);
        double ans = min((double) s1, (double) s2) /  max((double)s1, (double )s2) * 100;
        cout <<fixed << setprecision(2) << ans << "%"<< endl;
    }
}