class Solution {
public:
    string multiply(string num1, string num2) {
        int m=num1.size(),n=num2.size();
        if (num1 == "0" || num2 == "0") return "0";
        vector<int>ans(m+n,0);
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int temp=(num1[i]-'0')*(num2[j]-'0')+ans[i+j+1];
                ans[i+j]+=(temp/10);
                ans[i+j+1]=(temp%10);
            }
        }
        string str="";
        int i=0;
        while(ans[i]==0)
        {
            i++;
        }
        while(i<(m+n))
        {
            str.push_back(ans[i]+'0');
            i++;
        }
        return str;
    }
};