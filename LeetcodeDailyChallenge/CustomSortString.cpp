/* 11-MAr-2024
Leetcode Question no 791 Custom Sort String
You are given two strings order and s. 
  All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, 
  if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

  */

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>check(26,0);
        for(auto i:s)
        {
            check[i-'a']++;
        }
        string ans="";
        for(auto i:order)
        {
            while(check[i-'a']--)
            {
                ans.push_back(i);
            }
        }
        for(auto i:s)
        {
            if(check[i-'a']>0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
