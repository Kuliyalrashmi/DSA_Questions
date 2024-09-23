class Solution {
public:
    int solve(int index,int n,string &s,unordered_set<string>&st,vector<int>&dp)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        string curr="";
        int minE=n;
        for(int i=index;i<n;i++)
        {
            curr.push_back(s[i]);
            int extra=(st.find(curr)==st.end())?curr.size():0;
            int next=solve(i+1,n,s,st,dp);
            int total=extra+next;
            minE=min(minE,total);

        }
        return dp[index]=minE;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        unordered_set<string>st;
        for(auto word:dictionary)
        {
            st.insert(word);
        }
        vector<int>dp(51,-1);
        return solve(0,n,s,st,dp);
    }
};