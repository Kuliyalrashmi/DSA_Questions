class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans="";
        for(auto ch:s)
        {
            if(ch=='(')
            {
                if(!st.empty())
                {
                    ans.push_back(ch);
                }
                st.push(ch);
            }
            else
            {
                if(st.size()>1)
                {
                    ans.push_back(ch);
                }
                st.pop();
            }
        }
        return ans;
    }
};