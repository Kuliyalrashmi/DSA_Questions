class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)
        {
            sum+=i;
        }
        if(sum%2!=0)
        {
            return false;
        }
        int n=nums.size();
        vector<vector<bool>>dp(n,vector<bool>(sum/2+1,false));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if(nums[0]<=sum/2)
        {
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int target=1;target<=(sum/2);target++)
            {
                int exclude=dp[i-1][target];
                int include=false;
                if(nums[i]<=target)
                {
                    include=dp[i-1][target-nums[i]];
                }
                dp[i][target]=exclude||include;
            }
        }
        return dp[n-1][sum/2];
    }
};