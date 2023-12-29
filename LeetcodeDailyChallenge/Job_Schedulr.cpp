/*  29-Dec-2023
Leetcode Question no 1335 Minimum Difficulty of A Job Schedule
You want to schedule a list of jobs in d days. Jobs are dependent 
(i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties
of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

  */
class Solution {
public:
    int solve(vector<int>& jobDifficulty,int n,int i,int d,int dp[301][11])
    {
        if(d==1)
        {
            return *max_element(begin(jobDifficulty)+i,end(jobDifficulty));
        }
        if(dp[i][d]!=-1)
        {
            return dp[i][d];
        }
        int Max=INT_MIN;
        int result=INT_MAX;
        for(int j=i;j<=n-d;j++)
        {
            Max=max(Max,jobDifficulty[j]);
            result=min(result,Max+solve(jobDifficulty,n,j+1,d-1,dp));
        }
        return dp[i][d]=result;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d)
        {
            return -1;
        }
        int dp[301][11];
        memset(dp,-1,sizeof(dp));
        return solve(jobDifficulty,n,0,d,dp);
    }
};
