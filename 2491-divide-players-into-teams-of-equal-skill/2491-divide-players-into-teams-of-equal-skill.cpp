class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long total_skill=0;
        for(auto s:skill)
        {
            total_skill+=s;
        }
        int n=skill.size();
        total_skill/=(n/2);
        int start=0,end=n-1;
        long long chemistry=0;
        while(start<end)
        {
            if(skill[start]+skill[end]!=total_skill)
            {
                return -1;
            }
            chemistry+=(long long)skill[start]*skill[end];
            start++;
            end--;
        }
        return chemistry;
    }
};