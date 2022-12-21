#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Skill
{
    string mName;
    int mValue;
    Skill(const string &name, int value) : mName(name), mValue(value) {}
};

struct CmpSkillByName
{
    bool operator()(const Skill &a, const Skill &b) const
    {
        return a.mName < b.mName;
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    int nSkills;
    cin >> nSkills;

    int nDescription;
    cin >> nDescription;

    vector<Skill> skills;
    for (int i = 0; i < nSkills; i++)
    {
        string name;
        cin >> name;
        int value;
        cin >> value;
        skills.emplace_back(name, value);
    }

    sort(begin(skills), end(skills), CmpSkillByName());

    for (int i = 0; i < nDescription; i++)
    {
        int salary = 0;
        for (string w; cin >> w && w != ".";)
        {
            auto it = lower_bound(begin(skills), end(skills), Skill(w, 0), CmpSkillByName());

            if (it != end(skills) && it->mName == w)
            {
                salary += it->mValue;
            }
        }
        cout << salary << "\n";
    }
}