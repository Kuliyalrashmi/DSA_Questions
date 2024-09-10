class Solution {
public:
    void merge(vector<long long>&prefix,int start,int mid,int end)
    {
        vector<long long>temp;
        int left=start,right=mid+1;
        while(left<=mid&&right<=end)
        {
            if(prefix[left]<=prefix[right])
            {
                temp.push_back(prefix[left]);
                left++;
            }
            else
            {
                temp.push_back(prefix[right]);
                right++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(prefix[left]);
            left++;
        }
        while(right<=end)
        {
            temp.push_back(prefix[right]);
            right++;
        }
        for(int i=start;i<=end;i++)
        {
            prefix[i]=temp[i-start];
        }
    }
    void count(vector<long long>&prefix,int start,int mid,int end,long long lower,long long upper,int& ans)
    {
        int i=start;
        int start_i=mid+1;
        int end_i=mid+1;
        while(i<=mid)
        {
            while(start_i<=end&&(prefix[start_i]-prefix[i])<lower)
            {
                start_i++;
            }
            while(end_i<=end&&(prefix[end_i]-prefix[i])<=upper)
            {
                end_i++;
            }
            ans+=(end_i-start_i);
            i++;
        }
    }
    void mergeSort(vector<long long>&prefix,int start,int end,long long lower,long long upper,int &ans)
    {
        if(start>=end)
        {
            return;
        }
        int mid=start+(end-start)/2;
        mergeSort(prefix,start,mid,lower,upper,ans);
        mergeSort(prefix,mid+1,end,lower,upper,ans);
        count(prefix,start,mid,end,lower,upper,ans);
        merge(prefix,start,mid,end);
        return;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size(),ans=0;
        vector<long long>prefix(n+1,0);
        if(n==0)
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+(long long)nums[i];
        }
        mergeSort(prefix,0,n,(long long)lower,(long long)upper,ans);
        return ans;
    }
};