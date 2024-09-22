class Solution {
public:
     void solve(string &s,vector<string>temp,vector<vector<string>>&ans,int index, vector<vector<bool>>&dp)
    {
        if(index==s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(dp[index][i])
            {
                temp.push_back(s.substr(index,i-index+1));
                solve(s,temp,ans,i+1,dp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       int n=s.size();
       vector<vector<string>>ans;
       vector<string>temp;
       vector<vector<bool>>dp(n,vector<bool>(n,false));
       for(int i=0;i<n;i++)
       {
           dp[i][i]=true;
       }
       for(int l=2;l<=n;l++)
       {
           for(int i=0;i<n-l+1;i++)
           {
               int j=i+l-1;
               if(s[i]==s[j])
               {
                   if(l==2)
                   {
                       dp[i][j]=true;
                   }
                   else
                   {
                       dp[i][j]=dp[i+1][j-1];
                   }
               }
           }
       }
       solve(s,temp,ans,0,dp);
       return ans;
       
    }
};