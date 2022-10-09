
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

int main()
{
    iostream::sync_with_stdio(false);

    string a, b;
    while (getline(cin, a) && getline(cin, b)) {

        int s1 = love(a), s2 = love(b);
        string ac, bc;
//        for (int i = 0; i < (int) a.size(); i++) {
//            if (isalpha(a[i]))
//                ac += tolower(a[i]);
//        }
//        for (int i = 0; i < (int) b.size(); i++) {
//            if (isalpha(b[i]))
//                bc += tolower(b[i]);
//        }
//        for (int i = 0; i < (int) ac.size(); i++) {
//            s1 += ac[i] - ('a' - 1);
//            int check = s1;
//            while (s1 >= 10) {
//                int sum = 0;
//                while (check > 0) {
//                    sum += check % 10;
//                    check /= 10;
//                }
//                s1 = sum;
//                check = sum;
//            }
//        }
//        for (int i = 0; i < (int) bc.size(); i++) {
//            s2 += bc[i] - ('a' - 1);
//            int check = s2;
//            while (s2 >= 10) {
//                int sum = 0;
//                while (check > 0) {
//                    sum += check % 10;
//                    check /= 10;
//                }
//                s2 = sum;
//                check = sum;
//            }
//        }
        double ans = (min((double) s2, (double) s1) / max((double) s2, (double) s1)) * 100;

        cout << fixed << setprecision(2) << ans << " %"
             << "\n";
   
    }
}