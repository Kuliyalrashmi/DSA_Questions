class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums,int index,int k)
    {
        if(index==nums.size())
        {
            if(temp.size()==k)
            {
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(nums[index]);
        solve(ans,temp,nums,index+1,k);
        temp.pop_back();
        solve(ans,temp,nums,index+1,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp,nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        solve(ans,temp,nums,0,k);
        return ans;
    }
};