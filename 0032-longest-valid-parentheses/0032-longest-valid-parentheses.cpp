class Solution {
public:
    int longestValidParentheses(string s) {
        int count=0,n=s.size(),temp=0;
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
        int ans=0;
        count=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='@')
            {
                ans=max(ans,count);
                count=0;
            }
            else
            {
                count++;
            }
        }
        ans=max(ans,count);
        return ans;
    }
};