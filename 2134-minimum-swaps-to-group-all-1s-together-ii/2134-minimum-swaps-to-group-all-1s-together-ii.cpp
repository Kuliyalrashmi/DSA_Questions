class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int ones=0;
        vector<int>temp(2*n);
        for(int i=0;i<2*n;i++)
        {
            temp[i]=nums[i%n];
        }
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
            if(temp[end]==1)
            {
                curr_ones++;
            }
            if(end-start+1>ones)
            {
                curr_ones-=temp[start];
                start++;
            }
            swaps=max(swaps,curr_ones);
            end++;
        }
        return (ones-swaps);
    }
};