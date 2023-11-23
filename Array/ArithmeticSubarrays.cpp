/* Leetcode Question No 1630 Arithmetic Subarrays
A sequence of numbers is called arithmetic if it consists of at least two elements, 
and the difference between every two consecutive elements is the same. More formally,
a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.
  
For example, these are arithmetic sequences:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
  
The following sequence is not arithmetic:
1, 1, 2, 5, 7
  
You are given an array of n integers, nums, and two arrays of m integers each, l and r,
representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.
Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] 
can be rearranged to form an arithmetic sequence, and false otherwise.
*/

/* Brute Force Solution*/

class Solution {
public:
    bool check(vector<int>&nums)
    {
        sort(nums.begin(),nums.end());
        if(nums.size()<2)
        {
            return true;
        }
        int diff=nums[1]-nums[0];
        int n=nums.size();
        for(int i=1;i<n-1;i++)
        {
            if(nums[i+1]-nums[i]!=diff)
            {
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=l.size();
        vector<bool>ans;
        for(int i=0;i<n;i++)
        {
            int start=l[i];
            int end=r[i];
            vector<int>temp;
            for(int i=start;i<=end;i++)
            {
                temp.push_back(nums[i]);
            }
            ans.push_back(check(temp));
        }
        return ans;
    }
};
