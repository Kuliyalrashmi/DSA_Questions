/* Leetcode Question no 35 Search Insert Position 
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
Time Complexity=O(n)
Space Complexity=O(1)
*/
int searchInsert(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1,ans=nums.size();
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]>=target)
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
