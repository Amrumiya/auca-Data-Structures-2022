
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    //string line; cin >> line;
    for(string line; getline(cin, line);) {

        string buff;
        for(auto c: line) {
            if(isalpha(c)) {
                buff += tolower(c);
            }
        }

        //value sematics
        string copy = buff;
        reverse(copy.begin(), copy.end());

        cout << (copy == buff) ?  "Palindrome\n" : "not Palindrome\n";

        cout << line << endl;

    }
// check for value sematics and reference sematics 

}