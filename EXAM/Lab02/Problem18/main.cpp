
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for(int nCourses; cin >> nCourses && nCourses != 0;) {
    
    int nCatergory;
    cin >> nCatergory;

    vector<int> courses (nCourses);
    for(auto &e : courses) cin >> e;

    bool hasPassed = true;

    for(int i = 0; i < nCatergory; i++) {
        int NumCourseCat;
        cin >> NumCourseCat;
        int mReq;
        cin >> mReq;

        vector<int> categCourses (NumCourseCat);
        for(auto &e : categCourses) cin >> e;

        sort(categCourses.begin(), categCourses.end());

        int take = 0;
        for(auto &e : courses)
        {
            take += binary_search(categCourses.begin(), categCourses.end(),e);

        }

        if(take < mReq)
        {
            hasPassed = false;
        }


        cout << (hasPassed ? "yes\n" : "no\n");




    } 


    }



}