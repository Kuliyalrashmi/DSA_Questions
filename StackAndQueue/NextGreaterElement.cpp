/*
Leetcode Question no 496 Next Greater Element I
The next greater element of some element x in an array is the first greater element
that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] 
and determine the next greater element of nums2[j] in nums2. If there is no next greater element, 
then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       vector ans(nums1.size(),-1);
       for(int i=0;i<nums1.size();i++)
       { int j=0;
         while(nums2[j]!=nums1[i])
      {
            j++;
       }
      for(int k=j+1;k<nums2.size();k++)
      {
        if(nums2[k]>nums2[j])
      {
        ans[i]=nums2[k];
        break;
       }
     }
    } 
     return ans;     
    }
};


/* 
  Leetcode Question No 503 Next Greater Element II
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]),
return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array,
which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=nums[i%n])
            {
                st.pop();
            }
            if(i<n)
            {
                if(!st.empty())
                {
                    ans[i]=st.top();
                }
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};

 
