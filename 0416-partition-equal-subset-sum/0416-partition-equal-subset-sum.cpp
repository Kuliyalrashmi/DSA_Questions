class Solution {
public:
    bool solve(vector<int>&nums,int n,int target,vector<vector<int>>&dp)
    {
        if(target==0)
        {
            return true;
        }
        if(n==0)
        {
            return nums[0]==target;
        }
        if(dp[n][target]!=-1)
        {
            return dp[n][target];
        }
        bool exclude=solve(nums,n-1,target,dp);
        bool include=false;
        if(nums[n]<=target)
        {
            include=solve(nums,n-1,target-nums[n],dp);
        }
        return dp[n][target]=include||exclude;
    }
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
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return solve(nums,n-1,sum/2,dp);
    }
};