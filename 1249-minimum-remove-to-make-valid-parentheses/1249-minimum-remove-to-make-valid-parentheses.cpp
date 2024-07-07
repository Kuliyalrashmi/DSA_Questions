class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        int count=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                count++;
            }
            else if(s[i]==')')
            {
                if(count>0)
                {
                    count--;
                }
                else 
                {
                    s[i]='@';
                }
            }
        }
        count=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')')
            {
                count++;
            }
            else if(s[i]=='(')
            {
                if(count>0)
                {
                    count--;
                }
                else
                {
                    s[i]='@';
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]!='@')
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};