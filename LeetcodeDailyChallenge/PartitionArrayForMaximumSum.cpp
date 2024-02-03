/*  3-Feb-2024
Leetcode Question no 1043 Partition Array for MAximum sum
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k.
After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated 
so that the answer fits in a 32-bit integer.
*/

/* Recursion  + Memoization*/

class Solution {
public:
    int solve(int index,vector<int>&arr,int k,int n,vector<int>&dp)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int curr_max=-1,sum=0;
        for(int j=index;j<n&&(j-index+1)<=k;j++)
        {
           curr_max=max(curr_max,arr[j]);
           sum=max(sum,((j-index+1)*curr_max)+solve(j+1,arr,k,n,dp));
        }
        return dp[index]=sum;
    } 
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(0,arr,k,n,dp);
    }
};

 
