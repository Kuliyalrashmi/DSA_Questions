/*Leetcode Question 56 Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;i++)
        {
            if(ans.back()[1]>=intervals[i][0])
            {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
 
