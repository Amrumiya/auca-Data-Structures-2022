
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for(int nCourses; cin >> nCourses && nCourses != 0;) 
    {
        int nCategories;
        cin >> nCategories;

        vector<int> courses(nCourses);
        for(auto &course : courses) 
        {
            cin >> course;
        }

        bool hasPassed = true;

        for(int i = 0; i < nCategories; i++) {
            int NumCourseCat;
            cin >> NumCourseCat;
            int mReq;
            cin >> mReq;

            vector<int> categCourses(NumCourseCat);
            for(auto &course : categCourses) 
            {
                cin >> course;
            }

            sort(categCourses.begin(), categCourses.end());

            int Take = 0;
            for(auto course : courses)
            {
                Take+= binary_search(categCourses.begin(), categCourses.end(), course);
            }

            if(Take < mReq) {
            hasPassed = false;
        }

     }
        cout << (hasPassed ? "yes\n" : "no\n");

    }
}