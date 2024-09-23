class Solution {
public:
    bool check(int left,int right,string &s)
    {
        while(left<right)
        {
            if(s[left]!=s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    int solve(int start,int end,string &s,vector<int>&dp)
    {
        if(start>=end||check(start,end,s))
        {
            return 0;
        }
        if(dp[start]!=-1)
        {
            return dp[start];
        }
        int ans=INT_MAX;
        for(int i=start;i<end;i++)
        {
            if(check(start,i,s))
            {
                int temp=solve(i+1,end,s,dp)+1;
                ans=min(ans,temp);
            }
        }
        return dp[start]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(0,n-1,s,dp);
    }
};