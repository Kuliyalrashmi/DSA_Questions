class Solution {
public:
    long long mod=1e9+7;
    long long solve(vector<int>&nums,vector<vector<long long>>&temp)
    {
        vector<int>left,right;
        int n=nums.size();
        if(n<=2)
        {
            return 1;
        }
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[0])
            {
                left.emplace_back(nums[i]);
            }
            else
            {
                right.emplace_back(nums[i]);
            }
        }
        int l=left.size(),r=right.size();
        long long lways=solve(left,temp)%mod;
        long long rways=solve(right,temp)%mod;
        return ((temp[n-1][r]*lways)%mod*rways)%mod;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>temp(n+1,vector<long long>(n+1,1));
        for(int i=0;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                temp[i][j]=(temp[i-1][j]+temp[i-1][j-1])%mod;
            }
        }
        
        int ans=(solve(nums,temp)-1)%mod;
        return ans;
    }
};