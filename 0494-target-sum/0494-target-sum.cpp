class Solution {
public:
    int solve(int n,vector<int>&nums,int target,vector<vector<int>>&dp)
    {
        if(n==0)
        {
            if(target==0&&nums[0]==0)
            {
                return 2;
            }
            if(target==0||target==nums[0])
            {
                return 1;
            }
            return 0;
        }
        if(dp[n][target]!=-1)
        {
            return dp[n][target];
        }
        int exclude=solve(n-1,nums,target,dp);
        int include=0;
        if(nums[n]<=target)
        {
            include=solve(n-1,nums,target-nums[n],dp);
        }
        return dp[n][target]=(include+exclude);
    }
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
        vector<vector<int>>dp(n,vector<int>(required+1,-1));
        return solve(n-1,nums,required,dp);
    }
};