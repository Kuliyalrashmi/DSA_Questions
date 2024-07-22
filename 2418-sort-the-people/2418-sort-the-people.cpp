class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>p;
        int n=names.size();
        for(int i=0;i<n;i++)
        {
            p.push_back({heights[i],names[i]});
        }
        sort(p.rbegin(),p.rend());
        names.clear();
        for(int i=0;i<n;i++)
        {
            names.push_back(p[i].second);
        }
       return names;
    }
};