/* 
Leetcode Question no 2264 Largest 3-Same-Digit Number In a String
You are given a string num representing a large integer. An integer is good if it meets the following conditions:
It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.
  
Note:
A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.
*/
class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size(),count=1;
        string str="";
        char ch=' ';
        for(int i=0;i<n-2;i++)
        {
            if(num[i]==num[i+1]&&num[i+1]==num[i+2])
            {
                if(num[i]>ch)
                {
                    ch=num[i];
                    continue;
                }
            }
        }  
        if(ch!=' ')
        {
            for(int i=0;i<3;i++)
            {
                str+=ch;
            }
        } 
        return str;
    }
};
 
