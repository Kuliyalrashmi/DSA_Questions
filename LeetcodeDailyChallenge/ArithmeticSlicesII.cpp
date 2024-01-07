/*  7-Jan-2024
Leetcode Question no 446 Arithmetic Slice-II Subsequence
Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements
and if the difference between any two consecutive elements is the same.

For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The test cases are generated so that the answer fits in 32-bit integer.

*/


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        unordered_map<long,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            long num=nums[i];
            if(!mp.count(num))
            {
                mp[num]=vector<int>();
            }
            mp[num].push_back(i);
        }
        int sum=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long ele=2L*nums[i]-nums[j];
                if(mp.count(ele))
                {
                    for(int k:mp[ele])
                    {
                        if(k<i)
                        {
                            dp[i][j]+=dp[k][i]+1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                sum+=dp[i][j];
            }
        }
        return sum;
    }
};
