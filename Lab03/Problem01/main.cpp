
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

        cout << rank[card % 13] << "of " << suits[card / 13] << "\n";
        }

}

vector<vector<int>> readShuffles() {

    int num;
    cin >> num;

    vector< vector<int>> result(num, vector<int>(52));

    for(int i = 0; i < sz(result); i++) {
        for(int j = 0; j < 52; j++) {
            cin >> result[i][j];
        }
    }
    return result;
}

vector<int> applyShuffleToDeck(vector<int> deck, vector<int> shufle) {

    vector<int> temp(52);
    for(int i = 0; i < (int) shufle.size(); i++) {
        temp[i] = deck[shufle[i] - 1];
    }
    return temp;
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