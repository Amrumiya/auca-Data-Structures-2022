
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

  vector<string> song = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you",
                           "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    int input;
    cin >> input;
    vector<string> NumPeople(input);

    for (auto &e : NumPeople)
    {
        cin >> e;
    }

    int person = 0;
    int word = 0;
    bool isDone = false;

    for (;;)
    {
        cout << NumPeople[person] << ": " << song[word] << "\n";
        if (person == input - 1)
        {
            isDone = true;
        }

        if (word == sz(song) - 1 && isDone)
        {
            break;
        }

        ++person;
        ++word;

        if (person == input)
        {
            person = 0;
        }
        if (word == sz(song))
        {
            word = 0;
        }
    }
}   