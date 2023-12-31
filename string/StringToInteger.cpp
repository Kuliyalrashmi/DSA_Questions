/* Leetcode Question No 8  String To Integer(atoi) 

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. 
Read this character in if it is either. This determines if the final result is negative or positive respectively.
Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached.
The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). 
If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], 
then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:
Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

*/
class Solution {
public:
    int myAtoi(string s) {
       int n=s.size(),num=0;
       bool negative=false;
       int i=0;
       while(s[i]==' ')
       {
           i++;
       } 
       if(s[i]=='-')
       {
           negative=true;
           i++;
       }
       else if(s[i]=='+')
       {
           i++;
       }
       while(i<n&&(s[i]>='0'&&s[i]<='9'))
       {
           if(num>INT_MAX/10||(num==INT_MAX/10&&(s[i]-'0')>INT_MAX%10))
           {
               if(negative)
               {
                   return INT_MIN;
               }
               return INT_MAX;
           }
           num=num*10+(s[i]-'0');
           i++;
       }
       if(negative)
       {
           num=-num;
       }
       return num;
    }
};


/* Recursive Solution*/

long long solve(string s,int sign,int i,long long ans)
{
    if((sign*ans)>=INT_MAX)
    {
        return INT_MAX;
    }
    if((sign*ans)<=INT_MIN)
    {
        return INT_MIN;
    }
    if(s[i]==' '|| !isdigit(s[i]))
    {
        return ans*sign;
    }
    int no=s[i]-'0';
    return solve(s,sign,i+1,ans*10+no);
}
int createAtoi(string s) {
    int n=s.size(),sign=1,i=0;
    long long ans=0;
    while(i<n&&s[i]==' ')
    {
        i++;
    }
    if(s[i]=='-')
    {
        sign=-1;
        i++;
    }
    else if(s[i]=='+')
    {
        sign=1;
        i++;
    }
    return solve(s,sign,i,ans);
}
