/* Leetcode Question no 540 Single Element in A sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice,
except for one element which appears exactly once.
Return the single element that appears only once.
*/
/* Approach 1 using Xor of each Element
Time Complexity=O(n)*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=0;
        for(auto i:nums)
        {
            ans^=i;
        }
        return ans;
    }
};


/* Approach 2 USing Binary Search
Time Complexity=O(logn)
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        if(nums[0]!=nums[1])
        {
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2])
        {
            return nums[n-1];
        }
        int start=1,end=n-2;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]!=nums[mid+1]&&nums[mid-1]!=nums[mid])
            {
                return nums[mid];
            }
            else if(mid%2==1&&nums[mid]==nums[mid-1]||mid%2==0&&nums[mid]==nums[mid+1])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return -1;
    }
};
