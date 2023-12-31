/*    31-Dec-2023

Leetcode Question no 1624 Largest Substring Between Two Equal Characters
Given a string s, return the length of the longest substring between two equal characters, 
excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.

*/
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int>mp;
        int ans=-1,n=s.size();
        for(int i=0;i<n;i++)
        {
           if(mp.find(s[i])==mp.end())
           {
               mp[s[i]]=i;
           }
           else
           {
                ans=max(ans,i-mp[s[i]]-1);
           }
        }
        return ans;
    }
};
