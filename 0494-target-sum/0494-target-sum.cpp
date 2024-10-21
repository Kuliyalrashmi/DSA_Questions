class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(),sum=0;
        for(auto num:nums)
        {
            sum+=num;
        }
        int required=sum-target;
        if(required<0)
        {
            return 0;
        }
        if(required%2==1)
        {
            return 0;
        }
        required/=2;
        vector<vector<int>>dp(n,vector<int>(required+1,0));
        if(nums[0]==0)
        {
            dp[0][0]=2;
        }
        else
        {
            dp[0][0]=1;
        }
        if(nums[0]!=0&&nums[0]<=required)
        {
            dp[0][nums[0]]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int target=0;target<=required;target++)
            {
                int exclude=dp[i-1][target];
            int include=0;
            if(nums[i]<=target)
            {
                include=dp[i-1][target-nums[i]];
            }
            dp[i][target]=include+exclude;
            }
        }
        return dp[n-1][required];
    }
};