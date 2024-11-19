class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<int>left_sum(n,0),right_sum(n,0);
        for(int i=1;i<n;i++)
        {
            left_sum[i]=left_sum[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            right_sum[i]=right_sum[i+1]+nums[i+1];
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                if(left_sum[i]==right_sum[i])
                {
                    ans+=2;
                }
                else if(abs(left_sum[i]-right_sum[i])==1)
                {
                    ans+=1;
                }
            }
        }
        return ans;
    }
};