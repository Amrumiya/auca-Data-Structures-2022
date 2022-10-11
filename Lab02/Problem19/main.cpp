#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);


    const int FirstCharacter = 0;
    const int SecondCharacter = 1;


    string line;
    getline(cin, line);
    int TestCase = stoi(line);

    for(int i = 0; i < TestCase; i++ )
    {
        getline(cin, line);
        istringstream sinp(line);
        int countM = 0;
        int countF = 0;
        int cnt    = 0;

        for (string l; sinp >> l;)
        {
            countM += l[FirstCharacter]  == 'M';
            countM += l[SecondCharacter] == 'M';

            countF += l[FirstCharacter]  == 'F';
            countF += l[SecondCharacter] == 'F';
            cnt++;
        }

        cout << (cnt > 1 && countF == countM ? "LOOP\n" : "NO LOOP\n");
    }
}
