/*   10-Feb-2024
Leetcode Question no 647 Palindromic Subsequence

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

*/

class Solution {
public:
    bool check(int start,int end,string s)
    {
        while(start<end)
        {
            if(s[start]!=s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(check(i,j,s))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
