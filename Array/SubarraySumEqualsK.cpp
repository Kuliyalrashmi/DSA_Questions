/* Leetcode 560 Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        int runningSum=0,ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            runningSum+=nums[i];
            int remain=runningSum-k;
            ans+=mp[remain];
            mp[runningSum]++;
        }
        return ans;
    }
};
