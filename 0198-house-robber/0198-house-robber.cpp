class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
           int include=nums[i];
           if(i>1)
           {
               include+=dp[i-2];
           }
           int exclude=dp[i-1];
           dp[i]=max(include,exclude);
        }
        return dp[n-1];
    }
};