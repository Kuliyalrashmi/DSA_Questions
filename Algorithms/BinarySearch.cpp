/* Binary Search Algorithm 
Efficient Searching Algorithm Works only on the sorted Array
Time Complexity=O(logn)
Space Complexity=O(1)
*/
int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(target<nums[mid])
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return -1;
    }
