/*  2-Jan-2023
Leetcode Question no 2610  Convert An Array Into 2D Array With Conditions

You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        vector<vector<int>>ans;
        while(!mp.empty())
        {
            vector<int>temp,zeroVec;
            for(auto &i:mp)
            {
                temp.push_back(i.first);
                i.second--;
                if(i.second==0)
                {
                    zeroVec.push_back(i.first);
                }
            }
            ans.push_back(temp);
            for(auto j:zeroVec)
            {
                mp.erase(j);
            }
        }
        return ans;
    }
};
