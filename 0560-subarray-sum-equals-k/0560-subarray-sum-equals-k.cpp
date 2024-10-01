class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        int prefix=0,ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            prefix+=nums[i];
            int remove=prefix-k;
            ans+=mp[remove];
            mp[prefix]++;
        }
        return ans;
    }
};