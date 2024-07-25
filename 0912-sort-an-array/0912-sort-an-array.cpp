class Solution {
public:
    void merge(int start,int end,int mid,vector<int>&nums)
    {
        int n1=mid-start+1;
        int n2=end-mid;
        int *first=new int[n1];
        int *second=new int[n2];
        for(int i=0;i<n1;i++)
        {
            first[i]=nums[start+i];
        }
        for(int i=0;i<n2;i++)
        {
            second[i]=nums[mid+i+1];
        }
        int index1=0,index2=0,k=start;
         while(index1<n1 && index2<n2)
        {
            if(first[index1]<=second[index2])
            {
                nums[k]=first[index1];
                index1++;
            }
            else
            {
                nums[k]=second[index2];
                index2++;
            }
            k++;
        }
        while(index1<n1)
        {
            nums[k]=first[index1];
            k++;
            index1++;
        }
        while(index2<n2)
        {
            nums[k]=second[index2];
            k++;
            index2++;
        }
        delete [] first;
        delete [] second;
    }
    void mergeSort(int start,int end,vector<int>&nums)
    {
        if(start>=end)
        {
            return;
        }
        int mid=start+(end-start)/2;
        mergeSort(start,mid,nums);
        mergeSort(mid+1,end,nums);
        merge(start,end,mid,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(0,n-1,nums);
        return nums;
    }
};