class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>mp(mx+1,0);
        for(auto i:nums)
        {
            mp[i]++;
        }
        int inc=0,exc=0;
        for(int i=1;i<=mx;i++)
        {
            int c=exc+mp[i]*i;
            exc=max(inc,exc);
            inc=c;
        }
        return max(inc,exc);
    }
};