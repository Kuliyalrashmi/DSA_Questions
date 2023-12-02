/*  1 December 2023
Leetcode Question no 1662  check If Two String Arrays are Equivalent
Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
A string is represented by an array if the array elements concatenated in order forms the string.
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m=word1.size(),n=word2.size();
        string str1="",str2="";
        for(int i=0;i<m;i++)
        {
           str1+=word1[i];
        }
        for(int i=0;i<n;i++)
        {
           str2+=word2[i];
        }
        return str1==str2;
    }
};
