class Solution {
public:
    void merge(int start,int mid,int end, vector<int> &nums)
    {
        int n1=mid-start+1;
        int n2=end-mid;
        int left[n1],right[n2];
        
        for(int i=0;i<n1;i++)
        {
            left[i]=nums[start+i];
        }
        for(int j=0;j<n2;j++)
        {
            right[j]=nums[mid+j+1];
        }
        int index1=0,index2=0,k=start;
        while(index1<n1&&index2<n2)
        {
            if(left[index1]<=right[index2])
            {
                nums[k++]=left[index1];
                index1++;
            }
            else
            {
                nums[k++]=right[index2++];
            }
        }
        while(index1<n1){
            nums[k++] = left[index1++];
        }
        while(index2<n2){
            nums[k++] = right[index2++];
        }
    }
    int countPairs(int start,int mid,int end,vector<int>&nums)
    {
        int count=0;
        int right=mid+1;
        for(int i=start;i<=mid;i++)
        {
            while(right<=end&&nums[i]>2LL*nums[right])
            {
                right++;
            }
            count+=(right-(mid+1));
        }
        return count;
    }
    int solve(int start,int end,vector<int>&nums)
    {
        int count=0;
        if(start>=end) return count;
        int mid=start+(end-start)/2;
        count+=solve(start,mid,nums);
        count+=solve(mid+1,end,nums);
        count+=countPairs(start,mid,end,nums);
        merge(start,mid,end,nums);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int start=0,end=n-1,ans=0;
        return solve(start,end,nums);
    }
};