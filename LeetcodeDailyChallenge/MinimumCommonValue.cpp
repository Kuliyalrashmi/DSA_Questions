/* 9-Mar-2024
Leetcode Question no 2450 Minimum Common Value
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
  return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.
*/
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int i=0,j=0;
        while(i<m&&j<n)
        {
            if(nums1[i]==nums2[j])
            {
                return nums1[i];
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return -1;
    }
};
