class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        mp[0]=1;
        int sum=0,ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int reminder=sum%k;
            if(reminder<0)
            {
                reminder+=k;
            }
            if(mp.find(reminder)!=mp.end())
            {
                ans+=mp[reminder];
            }
            mp[reminder]++;
        }
        return ans;
    }
};