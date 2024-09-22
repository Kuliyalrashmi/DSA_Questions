class Solution {
public:
    int solve(long long curr,long long n,long long next)
    {
        int count=0;
        while(curr<=n)
        {
            count+=(next-curr);
            curr*=10;
            next*=10;
            next=min(next,n+1);
        }
        return count;
    }
    int findKthNumber(int n, int k) {
        int curr=1;
        k-=1;
        while(k>0)
        {
            int count=solve(curr,n,curr+1);
            if(count<=k)
            {
                curr++;
                k-=count;
            }
            else
            {
                curr*=10;
                k-=1;
            }
        }
        return curr;
    }
};