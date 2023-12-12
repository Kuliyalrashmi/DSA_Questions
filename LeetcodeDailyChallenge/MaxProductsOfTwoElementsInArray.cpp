/*  12-Dec-2023
Leetcode Question no 1464 Maximum Products of Two Elements in array
Given the array of integers nums, you will choose two different indices i and j of that array. 
Return the maximum value of (nums[i]-1)*(nums[j]-1).
*/

/* With Sorting */


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return (nums[n-1]-1)*(nums[n-2]-1);
    }
};


/* without Sorting */


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int Maximum=INT_MIN,Second_max=INT_MIN;
        for(auto i:nums)
        {
            if(i>=Maximum)
            {
                Second_max=Maximum;
                Maximum=i;
            }
            else if(i<Maximum&&i>Second_max)
            {
                Second_max=i;
            }
        }
        return (Maximum-1)*(Second_max-1);
    }
};
