class Solution {
public:
    int solve(string s,int start,int end)
    {
        while(start>=0&&end<s.size()&&s[start]==s[end])
        {
            start--;
            end++;
        }
        return end-start-1;
    }
    string longestPalindrome(string s) {
        int i=0,j=0,max_len=INT_MIN,index,n=s.size();
        for(int i=0;i<n;i++)
        {
            int l1=solve(s,i,i);
            int l2=solve(s,i,i+1);
            int len=max(l1,l2);
            if(len>max_len)
            {
                max_len=len;
                index=i-(len-1)/2;
            }
        }
        return s.substr(index,max_len);
    }
};