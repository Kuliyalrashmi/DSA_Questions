/*
Leetcode Question no 20 Valid Parenthesis
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

*/

class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(ch=='('||ch=='{'||ch=='[')
            {
                st.push(ch);
            }
            else if(st.empty())
            {
                return false;
            }
            else if((st.top()=='('&&ch!=')')||(st.top()=='{'&&ch!='}')||st.top()=='['&&ch!=']')
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
        return st.empty();
    }
};
 
