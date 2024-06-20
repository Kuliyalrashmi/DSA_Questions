class Solution {
public:
    bool solve(int mid,vector<int>&position,int m)
    {
        int previous=position[0];
        int count=1;
        for(int i=1;i<position.size();i++)
        {
            int curr=position[i];
            if(curr-previous>=mid)
            {
                count++;
                previous=curr;
            }
            if(count==m)
            {
                return true;
            }
        }
        return count==m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int start=1,end=position[n-1]-position[0];
        int ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(solve(mid,position,m))
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
};