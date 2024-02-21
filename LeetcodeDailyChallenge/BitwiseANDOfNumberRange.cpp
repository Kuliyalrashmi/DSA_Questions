/*  21-feb-2024
Leetcode Question no 201 Bitwise AND of Number Range
Given two integers left and right that represent the range [left, right], 
return the bitwise AND of all numbers in this range, inclusive.
*/

/*  Approach 1 */

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right>left)
        {
            right=(right&(right-1));
        }
        return right;
    }
};


/* Approach 2 */

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift=0;
        while(left!=right)
        {
            left=(left>>1);
            right=(right>>1);
            shift++;
        }
        return (left<<shift);
    }
};
