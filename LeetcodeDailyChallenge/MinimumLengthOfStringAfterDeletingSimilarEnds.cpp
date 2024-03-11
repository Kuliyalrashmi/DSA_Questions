/*  5-MAr-2024
Leetcode Question no 1750 Minimum Length Of String After Deleting Similar Ends
Given a string s consisting only of characters 'a', 'b', and 'c'.
  You are asked to apply the following algorithm on the string any number of times:

Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
The prefix and the suffix should not intersect at any index.
The characters from the prefix and suffix must be the same.
Delete both the prefix and the suffix.
Return the minimum length of s after performing the above operation any number of times (possibly zero times).
*/

class Solution {
public:
    int minimumLength(string s) {
        int start=0,end=s.size()-1;
        while(start<end)
        {
            if(s[start]==s[end])
            {
                int ch=s[start];
                start++;
                end--;
               while(s[start]==ch&&start<=end)
               {
                start++;
               }
               while(s[end]==ch&&start<=end)
               {
                end--;
               }
            }
            else
            {
                return end-start+1;
            }
        }
        return end-start+1;
    }
};
