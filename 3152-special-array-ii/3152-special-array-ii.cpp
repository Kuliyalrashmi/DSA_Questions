class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m=nums.size(),n=queries.size();
        vector<bool>ans;
        vector<int>prefix(m);
        for(int i=1;i<m;i++)
        {
            prefix[i]=prefix[i-1]+((((nums[i]+nums[i-1])%2==0)?1:0));
        }
        for(int i=0;i<m;i++)
        {
            cout<<prefix[i]<<" ";
        }
        for(int i=0;i<n;i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            int same=prefix[end]-prefix[start];
            if(same==0)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};