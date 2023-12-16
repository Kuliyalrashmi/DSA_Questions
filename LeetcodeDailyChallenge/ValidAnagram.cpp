/*  16-Dec-2023
  
Leetcode Question no 242 Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[256]={};
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            hash[t[i]]--;
        }
        for(int i=0;i<256;i++)
        {
            if(hash[i])
            {
                return false;
            }
        }
        return true;
    }
};


 
