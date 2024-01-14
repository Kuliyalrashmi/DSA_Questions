/*   14-Jan-2024
  
Leetcode Question no 1657 Determine If Two Strings Are Close Or Not
Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character,
and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        if(m!=n)
        {
            return false;
        }
        vector<int>mp1(26,0);
        vector<int>mp2(26,0);
        for(int i=0;i<m;i++)
        {
            mp1[word1[i]-'a']++;
            mp2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(mp1[i]!=0&&mp2[i]!=0)
            {
                continue;
            }
            if(mp1[i]==0&&mp2[i]==0)
            {
                continue;
            }
            return false;
        }
        sort(mp1.begin(),mp1.end());
        sort(mp2.begin(),mp2.end());
        return mp1==mp2;
    }
};
