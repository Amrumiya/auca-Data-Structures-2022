
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int firstChannel, secondChannel;

    int firstResult;
    int secondResult;
    while (cin >> firstChannel >> secondChannel) {
        if (firstChannel && secondChannel == -1) break;
        if(firstChannel  > secondChannel) {
            int temp = firstChannel;
            firstChannel = secondChannel;
            secondChannel = temp;
        }

        firstResult = secondChannel - firstChannel;
        secondResult  = 100 - secondChannel + firstChannel ;
        cout << min(firstResult,secondResult) << endl;
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
