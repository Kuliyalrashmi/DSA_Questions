/* Leetcode Question No 796 Rotate String
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        int m=s.size(),n=goal.size();
        if(m!=n)
        {
            return false;
        }
        if(s==goal)
        {
            return true;
        }
        queue<int>q1,q2;
        for(int i=0;i<n;i++)
        {
            q1.push(s[i]);
            q2.push(goal[i]);
        }
        while(m--)
        {
            int x=q1.front();
            q1.pop();
            q1.push(x);
            if(q1==q2)
            {
                return true;
            }
        }
        return false;
    }
};


/* Second Approach using the functions of string */
  class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;

        return ((s+s).find(goal) != string::npos);
    }
};
