/*  16-Feb-2024
Leetcode Question no 1481 Least Number of Unique Integers After K Removals
Given an array of integers arr and an integer k. 
  Find the least number of unique integers after removing exactly k elements.
  */

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto i:arr)
        {
            mp[i]++;
        }
        vector<pair<int,int>>temp;
        for(auto i :mp)
        {
            temp.push_back({i.second,i.first});
        }
        sort(temp.begin(),temp.end());
        int j=0;
        int ans=temp.size();
        while(k>0)
        {
           while(temp[j].first>0&&k>0)
           {
               temp[j].first--;
               k--;
           }
           if(temp[j].first==0)
           {
               j++;
               ans--;
           }
        }
        return ans;
    }
};
