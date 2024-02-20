/*   20-Feb-2024
Leetcode Question no 268 Missing Number
Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int total_sum=n*(n+1)/2;
        int curr_sum=0;
        for(int i=0;i<n;i++)
        {
            curr_sum+=nums[i];
        }
        return total_sum-curr_sum;
    }

};

 
