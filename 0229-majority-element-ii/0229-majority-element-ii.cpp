class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int bound=int(n/3)+1;
        for(auto i:mp)
        {
            if(i.second>=bound)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};