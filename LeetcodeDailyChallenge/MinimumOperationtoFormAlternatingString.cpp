/*  24-Dec-2023
  
Leetcode Question no 1758 Minimum Changes to Make Binary String Alternative
You are given a string s consisting only of the characters '0' and '1'. 
In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. 
For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.
*/

class Solution {
public:
    int minOperations(string s) {
       int count0=0,count1=0,n=s.size();
       for(int i=0;i<n;i++)
       {
          if(i%2==0)
          {
            if(s[i]!='0')
            {
                count0++;
            }
            else
            {
                count1++;
            }
          }
          else
          {
            if(s[i]!='1')
            {
                count0++;
            }
            else
            {
              count1++;
            }
          }
        }
        return min(count0,count1);
    }
};
