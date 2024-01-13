/*    13-Jan-2024
  
Leetcode Question no 1347 Minimum Number Of Steps To MAke Two Strings Anagram
You are given two strings of the same length s and t.
In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.


*/

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        int count=0;
        for(auto i:s)
        {
            mp[i]++;
        }
        for(auto i:t)
        {
           if(mp.find(i)!=mp.end())
           {
                int ans=mp[i];
                ans--;
                mp[i]=ans;
           }
        }
        for(auto i:mp)
        {
            if(i.second>0)
            {
                count+=i.second;
            }
        }
        return count;
    }
};
