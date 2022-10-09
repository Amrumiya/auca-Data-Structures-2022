
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

 vector<string> messages(16);
    string birthday = " Happy birthday to you! Happy birthday to you! Happy birthday to Rujia! Happy birthday to you!!!";

    int j = 0;
    stringstream ssin(birthday);
    while (ssin.good() && j < 16) {
        ssin >> messages[j];
        ++j;
    }

    int n;
    cin >> n;
    vector<string> nPeople(n);

    for (auto &e : nPeople)
    {
        cin >> e;
    }

    int person = 0;
    int word = 0;
    bool isDone = false;

    for (;;)
    {
        cout << nPeople[person] << ": " << messages[word] << "\n";
        if (person == n - 1)
        {
            isDone = true;
        }

        if (word == (int) sz(messages) - 1 && isDone)
        {
            break;
        }

        ++person;
        ++word;

        if (person == n)
        {
            person = 0;
        }
        if (word == sz(messages))
        {
            word = 0;
        }
    }
}   