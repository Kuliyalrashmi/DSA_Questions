class Solution {
public:
    string reverseWords(string s) {
       stack<string>st;
       int n=s.size();
       string temp="";
       for(int i=0;i<n;i++)
       {
           if(s[i]==' '&&!temp.empty())
           {
               st.push(temp);
               temp.clear();
           }
           else if(s[i]!=' ')
           {
               temp+=s[i];
           }
       }
       if(!temp.empty())
       {
           st.push(temp);
       }
       string ans="";
       while(!st.empty())
       {
           ans+=st.top();
           st.pop();
           if(!st.empty())
           {
               ans+=' ';
           }
       }
       return ans;
    }
};