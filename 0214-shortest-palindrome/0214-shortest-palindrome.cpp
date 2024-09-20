class Solution {
public:
    int computeLPS(string s)
    {
        int i=1,j=0,length=0,n=s.size();
        vector<int>LPS(n,0);
        while(i<n)
        {
            if(s[i]==s[length])
            {
                length++;
                LPS[i]=length;
                i++;
            }
            else
            {
                if(length!=0)
                {
                   length=LPS[length-1];
                }
                else
                {
                    LPS[i]=0;
                    i++;
                }
            }
        }
        return LPS[n-1];
    }
    string shortestPalindrome(string s) {
        int n=s.size();
        string temp=s;
        reverse(temp.begin(),temp.end());
        int len=computeLPS(s+"#"+temp);
        string ans=temp.substr(0,temp.size()-len)+s;
        return ans;
    }
};