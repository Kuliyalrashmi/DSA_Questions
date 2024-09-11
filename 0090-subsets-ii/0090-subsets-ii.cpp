class Solution {
public:
    void solve(int index,vector<int>&nums,set<vector<int>>&st,vector<int>temp)
    {
        if(index>=nums.size())
        {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(index+1,nums,st,temp);
        temp.pop_back();
        solve(index+1,nums,st,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        vector<int>temp;
        solve(0,nums,st,temp);
        for(auto i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
};