class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod=1e9+7;
        vector<int>prefix;
        for(int i=0;i<n;i++)
        {
            prefix.push_back(nums[i]);
            for(int j=i+1;j<n;j++)
            {
                prefix.push_back(prefix.back()+nums[j]);
            }
        }
        sort(prefix.begin(),prefix.end());
        int sum=0;
        for(int i=left-1;i<right;i++)
        {
            sum=(sum%mod+prefix[i]%mod)%mod;
        }
        return sum;
    }
};