class Solution {
public:
    long long solve(int mid,vector<int>&piles)
    {
        int n=piles.size();
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=ceil((double)piles[i]/(double)mid);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int start=1,end=*max_element(piles.begin(),piles.end());
       while(start<=end)
       {
           int mid=start+(end-start)/2;
           long long temp=solve(mid,piles);
           if(temp<=h)
           {
               end=mid-1;
           }
           else
           {
               start=mid+1;
           }
       }
        return start;
    }
};