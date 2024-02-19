/*    19-Feb-2024
  
Leetcode Question no 231 Power Of Two
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

  */

/* Approach 1 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
        {
            return true;
        }
        else if(n<2)
        {
            return false;
        }
        while(n%2==0&&n!=0)
        {
            if(n!=2)
            {
                n=n/2;
            }
            else
            {
                n=0;
            }
        }
        return n==0;
    }
};


/* Approach 2 Bit Magic */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0&&!(n&n-1));
    }
};
