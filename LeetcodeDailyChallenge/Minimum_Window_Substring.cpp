/*  5-Feb-2024
Leetcode Question no 76 Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window.
If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

*/

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())
        {
            return "";
        }
        int n=s.size();
        unordered_map<char,int>mp;
        for(auto i:t)
        {
            mp[i]++;
        }
        int window_size=INT_MAX;
        int required_count=t.size(),i=0,j=0;
        int start_index=0;
        while(j<n)
        {
            if(mp[s[j]]>0)
            {
                required_count--;
            }
            mp[s[j]]--;
            while(required_count==0)
            {
                int current_size=j-i+1;
                if(current_size<window_size)
                {
                    window_size=current_size;
                    start_index=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                {
                    required_count++;
                }
                i++;
            }
            j++;
        }
        if(window_size==INT_MAX)
        {
            return "";
        }
        return s.substr(start_index,window_size);
    }
};
