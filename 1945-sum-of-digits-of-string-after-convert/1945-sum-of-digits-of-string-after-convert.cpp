class Solution {
public:
    int getLucky(string s, int k) {
        string temp;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            temp+=to_string((s[i]-'a'+1));
        }
        for(int i=0;i<temp.size();i++)
        {
            ans+=(temp[i]-'0');
        }
        k--;
        while(k!=0)
        {
            int num=ans;
            ans=0;
            while(num!=0){
                int a = num%10;
                num/=10;
                ans += a;
            }
            k--;
        }
        return ans;
    }
};