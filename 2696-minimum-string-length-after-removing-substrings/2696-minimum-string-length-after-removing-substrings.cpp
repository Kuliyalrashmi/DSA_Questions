class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        st.push(s[0]);
        int n=s.size();
        for(int i=1;i<n;i++)
        {
            string str="";
            if(st.size()>0)str+=st.top();
            str+=s[i];
            if(str=="AB"||str=="CD")
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.size();
    }
};