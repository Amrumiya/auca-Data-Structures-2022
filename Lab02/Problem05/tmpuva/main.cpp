
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

 int road, integ, devisor;
 int increment = 1;


 while(cin >> road >> integ) {

    if((road && integ) == 0) {
        break;
    }
    road--;
    devisor = road  / integ;
    
    if(devisor > 26) {
        cout << "Case " << increment++ <<": " << "impossible" <<'\n';
    } else {
        cout << "Case " << increment++ << ": " << devisor << '\n';
    }
 }













}