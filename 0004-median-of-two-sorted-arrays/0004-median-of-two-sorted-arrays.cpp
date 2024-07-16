class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,m=nums1.size(),n=nums2.size();
        vector<int>temp(m+n,0);
        int index=0;
        while(i<m&&j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                temp[index]=nums1[i];
                i++;
            }
            else
            {
                temp[index]=nums2[j];
                j++;
            }
            index++;
        }
        while(i<m)
        {
            temp[index]=nums1[i];
            index++;
            i++;
        }
        while(j<n)
        {
            temp[index]=nums2[j];
            index++;
            j++;
        }
        int x=temp.size();
        return x%2?temp[x/2]:(temp[x/2]+temp[x/2-1])/2.0;
    }
};