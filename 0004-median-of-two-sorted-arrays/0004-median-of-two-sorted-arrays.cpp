class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,m=nums1.size(),n=nums2.size();
        int total=m+n;
        int mid1=0,mid2=0;
        for(int index=0;index<=total/2;index++)
        {
            mid1=mid2;
            if(i<m&&j<n)
            {
                if(nums1[i]<=nums2[j])
                {
                    mid2=nums1[i];
                    i++;
                }
                else
                {
                    mid2=nums2[j];
                    j++;
                }
            }
            else if(i<m)
            {
                mid2=nums1[i];
                i++;
            }
            else if(j<n)
            {
                mid2=nums2[j];
                j++;
            }
        }
        return total%2!=0?mid2:(mid1+mid2)/2.0;
    }
};