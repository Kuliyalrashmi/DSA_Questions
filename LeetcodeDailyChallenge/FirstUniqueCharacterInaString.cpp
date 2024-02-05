/*  5-Feb-2024
Leetcode Question no 387 First Unique Character In a string
Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>map;
        for(int i=0;i<s.length();i++)
        {
            map[s[i]]++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(map[s[i]]==1)
            {
                return i;
            }
        }
        return -1;
    }
};

 
