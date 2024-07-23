class Solution {
public:
    int solve(vector<int>&nums)
    {
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
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        vector<int>first,second;
        for(int i=0;i<n;i++)
        {
            if(i!=n-1)
            {
                first.push_back(nums[i]);
            }
            if(i!=0)
            {
                second.push_back(nums[i]);
            }
        }
        return max(solve(first),solve(second));
    }
};