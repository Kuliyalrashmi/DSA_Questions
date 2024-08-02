class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int ones=0;
        for(auto it:nums)
        {
            if(it==1)
            {
                ones++;
            }
        }
        int curr_ones=0,start=0,end=0;
        int swaps=0;
        while(end<2*n)
        {
            if(nums[end%n]==1)
            {
                curr_ones++;
            }
            if(end-start+1>ones)
            {
                curr_ones-=nums[start%n];
                start++;
            }
            swaps=max(swaps,curr_ones);
            end++;
        }
        return (ones-swaps);
    }
};