class Solution {
public:
    vector<int>solve(int n)
    {
        vector<int>temp;
        temp.push_back(1);
        int val=1;
        for(int i=1;i<n;i++)
        {
            val*=(n-i);
            val/=i;
            temp.push_back(val);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++)
        {
            ans.push_back(solve(i));
        }
        return ans;
    }
};