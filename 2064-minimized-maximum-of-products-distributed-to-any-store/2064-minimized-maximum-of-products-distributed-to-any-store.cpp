class Solution {
public:
    bool possible(int x,vector<int>&quantites,int shops)
    {
        for(auto i:quantites)
        {
            shops-=(i+x-1)/x;
            if(shops<0)
            {
                return false;
            }
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int left=1,right=*max_element(quantities.begin(),quantities.end());
        int ans=0;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(possible(mid,quantities,n))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};