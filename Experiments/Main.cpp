#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int love(string s) {
    int sum = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z')
            sum += s[i] - 'a' + 1;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            sum += s[i] - 'A' + 1;
    }
    // Using modulo 9 to efficiently compute digit's sum.
    if (sum % 9 == 0)
        return 9;
    else
        return sum % 9;
}

int main() {
    string a, b;
    while (getline(cin, a) && getline(cin, b)) {

        int s1 = love(a), s2 = love(b);
        string ac, bc;

        double ans = (min((double) s2, (double) s1) / max((double) s2, (double) s1)) * 100;

        cout << fixed << setprecision(2) << ans << " %"
             << "\n";

    }

}