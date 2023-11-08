/* Leetcode Question no 34
Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
*/

/* Approach 1 using Linear search
Time Complexity=O(n)
Space Complexity=O(1)
*/
vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1,last=-1;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                count++;
                if(count==1)
                {
                    first=i;
                }
                if(count==1&&i==n-1)  // If Only 1 element is present in the array and that is the target
                {
                    first=i;
                    last=i;
                }
                else
                {
                    last=i;
                }
            }
        }
        return {first,last};
    }

/* Approach 2 Using Binary Search
Time Complexity=O(logn)
Space Complexity=O(1)
*/
vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1,last=-1;
        int n=nums.size(),start=0,end=n-1;
  //Find starting Index
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                first=mid;
                end=mid-1;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }

  
  //find last index
        start=0,end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                last=mid;
                start=mid+1;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return {first,last};
    }
