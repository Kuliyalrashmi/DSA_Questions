class Solution {
public:
    int partition(vector<int>&nums,int left,int right)
    {
        int p=nums[left];
        int i=left+1;
        int j=right;
        while(i<=j)
        {
            if(nums[i]<p&&nums[j]>p)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(nums[i]>=p)
            {
                i++;
            }
            if(nums[j]<=p)
            {
                j--;
            }
        }
        swap(nums[left],nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
       int n=nums.size();
        int left=0,right=n-1;
        int pivot=0;
        while(true)
        {
           pivot=partition(nums,left,right);
           if(pivot==k-1)
           {
               return nums[pivot];
           }
           else if(pivot>k-1)
           {
               right=pivot-1;
           }
           else
           {
               left=pivot+1;
           }
        }
        return nums[pivot];
    }
};