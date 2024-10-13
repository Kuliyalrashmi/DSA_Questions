class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=1,n=nums.size(),count=0;
        for(int i=1;i<n;i++)
        {
           if(nums[i]==nums[i-1])
           {
               count++;
           }
           else
           {
               count=0;
           }
           if(count<=1)
           {
               nums[j]=nums[i];
               j++;
           }
        }
       return j;
    }
};
