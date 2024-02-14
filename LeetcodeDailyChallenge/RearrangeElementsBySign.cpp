/*  14-Feb- 2024
  
Leetcode Question no 2149 Rearrange Array Elements By Sign
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

*/

/* Approach 1 Using Extra Space */
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                pos.push_back(nums[i]);
            }
            else if(nums[i]<0)
            {
                neg.push_back(nums[i]);
            }
        }
        nums.clear();
        for(int i=0;i<n/2;i++)
        {
            nums.push_back(pos[i]);
            nums.push_back(neg[i]);
        }
        return nums;
    }
};


/* Without Using Extra Space */
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int pos=0,neg=1;
       int n=nums.size();
       vector<int>ans(n);
       for(int i=0;i<n;i++)
       {
           if(nums[i]>0)
           {
               ans[pos]=nums[i];
               pos+=2;
           }
           else
           {
               ans[neg]=nums[i];
               neg+=2;
           }
       }
       return ans;
    }
};
