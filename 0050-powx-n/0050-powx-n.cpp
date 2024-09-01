class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long long original=n;
        if(n<0)
        {
            original=-original;
        }
        while(original>0)
        {
            if(original&1)
            {
                ans*=x;
                original-=1;
            }
            else
            {
                original/=2;
                x*=x;
            }
        }
        if(n<0)
        {
            ans=(1.0/ans);
        }
        return ans;
    }
};