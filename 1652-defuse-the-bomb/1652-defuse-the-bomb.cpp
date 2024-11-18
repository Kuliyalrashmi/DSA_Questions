class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n,0);
        if(k==0)
        {
            return ans;
        }
        int i=0;
        while(i<n)
        {
            int sum=0;
            if(k>0)
            {
                for(int j=1;j<=k;j++)
                {
                   sum+=code[(i+j)%n];
                }
            }
            else
            {
                for(int j=1;j<=-k;j++)
                {
                    sum+=code[(i-j+n)%n];
                }
            }
            ans[i]=sum;
            i++;
        }
        return ans;
    }
};