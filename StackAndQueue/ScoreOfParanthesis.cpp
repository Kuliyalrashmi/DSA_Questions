/*  Leetcode Question no 856 Score Of Parantheses
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.

*/
class Solution {
public:
    int scoreOfParentheses(string s) {
        int curr=0;
        stack<int>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(curr);
                curr=0;
            }
            else
            {
                curr=st.top()+max(2*curr,1);
                st.pop();
            }
        }
        return curr;
    }
};
