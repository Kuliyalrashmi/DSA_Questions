/*  12-Feb-2024
Leetcode Question no 169 Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
  
You may assume that the majority element always exists in the array.

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_index=0,count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[maj_index]==nums[i])
            {
                count++;
            }
            else
                count--;
            if(count==0)
            {
                maj_index=i;
                count=1;
            }
        }
        return nums[maj_index];
    }
};
