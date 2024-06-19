class Solution {
public:
    int Possibility(vector<int>v,int day,int m,int k)
    {
        int n=v.size();
        int count=0,totalB=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]<=day)
            {
                count++;
            }
            else
            {
               totalB+=(count/k);
               count=0;
            }
        }
        totalB+=(count/k);
        if(totalB>=m)
        {
            return 1;
        }
        return -1;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<m*1ll*k*1ll)
        {
            return -1;
        }
        int max_element=INT_MIN, min_element=INT_MAX;
        for(int i=0;i<n;i++)
        {
            max_element=max(max_element,bloomDay[i]);
            min_element=min(min_element,bloomDay[i]);
        }
        int start=min_element,end=max_element;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(Possibility(bloomDay,mid,m,k)==1)
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