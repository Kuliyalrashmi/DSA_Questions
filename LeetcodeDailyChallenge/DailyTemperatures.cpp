/*   31-Jan-2024
Leetcode Question no 739 Daily Temperatures
Given an array of integers temperatures represents the daily temperatures, 
  return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.

  */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
           while(!st.empty()&&temperatures[st.top()]<temperatures[i])
           {
               ans[st.top()]=i-st.top();
               st.pop();
           }
           st.push(i);
        }
        return ans;
    }
};

 
