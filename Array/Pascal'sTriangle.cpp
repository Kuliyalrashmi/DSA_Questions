/*Leetcode 118 Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/

 vector<int> create(int num)
    {
        vector<int>ans;
        long long int value=1;
        ans.push_back(value);
        for(int col=1;col<num;col++)
        {
            value=value*(num-col);
            value=value/col;
            ans.push_back(value);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>out;
        for(int i=1;i<=numRows;i++)
        {
            out.push_back(create(i));
        }
        return out;
    }
