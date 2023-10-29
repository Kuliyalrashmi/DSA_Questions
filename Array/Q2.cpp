/* leetcode 75 Sort Colours
Approach 1 (Basic Approach)
*/
void sortColors(vector<int>& nums) {
        int c0=0,c1=0,c2=0;
        for(auto it:nums)
        {
            if(it==0)
            {
                c0++;
            }
            else if(it==1)
            {
                c1++;
            }
            else
            {
                c2++;
            }
        }
        int i=0;
        while(c0--)
        {
            nums[i++]=0;
        }
        while(c1--)
        {
            nums[i++]=1;
        }
        while(c2--)
        {
            nums[i++]=2;
        }
    }


/* Approach 2 (Using DNF Sort Algorithm)*/
void sortColors(vector<int>& nums) {
        int left=0,end=nums.size()-1,mid=0;
        while(mid<=end)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[left]);
                left++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[end]);
                end--;
            }
        }
    }
