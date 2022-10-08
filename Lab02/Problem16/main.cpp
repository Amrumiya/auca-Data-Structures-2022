
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
    while (ssin.good() && j < 16){
        ssin >> messages[j];
        ++j;
    }
    
    int num;
    cin>> num;
    bool mom, girlfriend;
    for(int i = 0; i < sz(messages); i++) {
    if(i % 2 != 0) {
        if(mom) {cout << "Mom" << messages[i] << '\n'; mom = false; girlfriend = true;}
        if(girlfriend) {cout << "Girldfriend" << messages[i] << '\n'; girlfriend = false;
        mom = true;}
    }
    if(i % 2 == 0) cout << "Dad" << messages[i] << '\n';    
    }
    
    
}   