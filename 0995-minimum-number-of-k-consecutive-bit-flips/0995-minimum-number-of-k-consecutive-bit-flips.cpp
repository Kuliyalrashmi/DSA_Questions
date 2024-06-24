class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int flips=0;
        vector<bool>temp(n,false);
        int prev=0;
        for(int i=0;i<n;i++)
        {
            if(i>=k&&temp[i-k]==true)
            {
                prev--;
            }
            if(prev%2==nums[i])
            {
                if(i+k>n)
                {
                    return -1;
                }
                prev++;
                temp[i]=true;
                flips++;
            }
        }
        return flips;
    }
};