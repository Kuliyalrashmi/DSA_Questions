/*    1-Feb-2024
  
Leetcode Question no 2966 Divide Array Into arrays of Max Difference
You are given an integer array nums of size n and a positive integer k.

Divide the array into one or more arrays of size 3 satisfying the following conditions:

Each element of nums should be in exactly one array.
The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions,
return an empty array. And if there are multiple answers, return any of them.

*/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n;i+=3)
        {
            if(abs(nums[i+2]-nums[i])<=k)
            {
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
            }
            else
            {
                return {};
            }
        }
        return ans;
    }
};
