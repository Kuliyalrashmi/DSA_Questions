class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int curr=0;
        for(auto i:s)
        {
            if(i=='(')
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