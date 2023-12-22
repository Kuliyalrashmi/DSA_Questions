/*   22-Dec-2023
Leetcode Question no 1422 Maximum Score After Splitting A String
Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings 
(i.e. left substring and right substring).
The score after splitting a string is the number of zeros in the left substring plus 
the number of ones in the right substring.

*/


class Solution {
public:
    int maxScore(string s) {
        int zeros=0,ones=0;
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++)
        {
          if(s[i]=='1')
            {
             ones++;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='1')
            {
                ones--;
                ans=max(ans,ones+zeros);
            }
            else
            {
                zeros++;
                ans=max(ans,ones+zeros);
            }
        }
        return ans;
    }
};
