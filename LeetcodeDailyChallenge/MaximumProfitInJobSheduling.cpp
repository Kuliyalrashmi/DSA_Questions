/*  6-Jan-2023
Leetcode Question no 1235 Maximum Profit On Job Scheduling
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], 
obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit
you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

*/


class Solution {
public:
    int n;
    int dp[50001];
    int solve(vector<vector<int>>&temp,int i,vector<int>&st)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int next=lower_bound(st.begin(),st.end(),temp[i][1])-st.begin();
        int taken=temp[i][2]+solve(temp,next,st);
        int not_taken=solve(temp,i+1,st);
        return dp[i]=max(taken,not_taken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>temp(n,vector<int>(3,0));
        for(int i=0;i<n;i++)
        {
            temp[i][0]=startTime[i];
            temp[i][1]=endTime[i];
            temp[i][2]=profit[i];
        }
        auto comp=[&](auto&vect1,auto&vect2)
        {
            return vect1[0]<=vect2[0];
        };
        sort(begin(temp),end(temp),comp);
        sort(startTime.begin(),startTime.end());
        return solve(temp,0,startTime);
    }
};
