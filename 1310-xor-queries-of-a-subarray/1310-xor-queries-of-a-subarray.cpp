class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        int n=arr.size();
        vector<int>prefix;
        prefix.push_back(arr[0]);
        for(int i=1;i<n;i++)
        {
            prefix.push_back(arr[i]^prefix.back());
        }
        for(auto query:queries)
        {
            int left=query[0],right=query[1];
            int value=left==0?prefix[right]^0:prefix[right]^prefix[left-1];
            ans.push_back(value);
        }
        return ans;
    }
};