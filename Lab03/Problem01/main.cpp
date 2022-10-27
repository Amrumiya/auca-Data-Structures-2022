
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

vector<int> createDeck()
{
    vector<int> deck(52);
    for(int i = 0; i < sz(deck); i++) {
        deck[i] = i;
    }
    return deck;
}

void printDeck(const vector<int> &deck) {
        static vector<string> suits = {"Clubs", "Dimonds", "Hearts", "Spades"};
        static vector<string> rank = {"1", "2", "3", "4", "5", "6", "7","8","9","10","11","12", "13"};

    /*for(int i = 0; i < sz(deck); i++) 
    {
        cout << rank[i % 13] << "of" << suits[cards / 13] << "\n";
    }
    */

        for(auto card : deck) {

        cout << rank[card % 13] << " of " << suits[card / 13] << "\n";
        }

}



int main()
{
    iostream::sync_with_stdio(false);

    int TestCase;
    cin >> TestCase;
    for(int i = 0; i < TestCase; TestCase++) {

      auto suffles = readShuffles();
      auto deck = createDeck();

        for(string line; getline(cin, line) && !(line.empty());)
        {
            int ToInt = stoi(line);            
            applyShuffleToDeck(deck, suffles[ToInt - 1]);
        }

        if(TestCase != 0) cout << "\n";
        printDeck(deck);
    }
}