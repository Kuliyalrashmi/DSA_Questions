/* 
Leetcode Question No 1685 Sum of Absolute Differences In Sorted Array
You are given an integer array nums sorted in non-decreasing order.
Build and return an integer array result with the same length as nums such that result[i] 
is equal to the summation of absolute differences between nums[i] and all the other elements in the array.
In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).
*/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int left_sum=0,right_sum=0;
        for(int i=0;i<n;i++)
        {
            right_sum+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            ans.push_back((nums[i]*i-left_sum)+(right_sum-(nums[i]*(n-i))));
            left_sum+=nums[i];
            right_sum-=nums[i];
        }
        return ans;
    }
};
