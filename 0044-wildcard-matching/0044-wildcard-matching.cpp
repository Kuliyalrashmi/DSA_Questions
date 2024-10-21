class Solution {
public:
   bool calculate(string &str,int n)
   {
       for(int i=1;i<=n;i++)
       {
           if(str[i-1]!='*')
           {
               return false;
           }
       }
       return true;
   }
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,false));
        dp[0][0]=true;
        for(int j=1;j<=m;j++)
        {
            dp[j][0]=false;
        }
        for(int i=1;i<=n;i++)
        {
            dp[0][i]=calculate(p,i);
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    if(p[j-1]=='*')
                    {
                        
                        dp[i][j]=dp[i-1][j]||dp[i][j-1];
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
            }
        }
        return dp[m][n];
    }
};