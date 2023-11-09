/* Leetcode 1759 Count Number OF Homogeneous Substrings
Given a string s, return the number of homogenous substrings of s. 
Since the answer may be too large, return it modulo 109 + 7.
A string is homogenous if all the characters of the string are the same.
A substring is a contiguous sequence of characters within a string.
*/
class Solution {
public:
    int countHomogenous(string s) {
        int M=1e9+7;
        int ans=1,count=1,n=s.size();
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                count=1;
                ans+=count;
            }
            else
            {
                count++;
                ans+=count;
                ans=ans%M;
            }
        }
        ans=ans%M;
        return ans;
    }
};
