class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int max_count=0;
        int n=nums.size(),count=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]+1)
            {
                count++;
                max_count=max(max_count,count);
            }
            else if(nums[i]==nums[i-1])
            {
                continue;
            }
            else
            {
               max_count=max(max_count,count);
               count=1;
            }
        }
       return max(max_count,count);
    }
};