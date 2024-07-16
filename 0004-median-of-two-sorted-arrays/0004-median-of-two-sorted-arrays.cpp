class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total=nums1.size()+nums2.size();
        int i=0,j=0,first=0,second=0;
        for(int count=0;count<=total/2;count++)
        {
            first=second;
            if(i<nums1.size()&&j<nums2.size())
            {
                if(nums1[i]<=nums2[j])
                {
                    second=nums1[i++];
                }
                else
                {
                    second=nums2[j++];
                }
            }
            else if(i<nums1.size())
            {
                second=nums1[i++];
            }
            else
            {
                second=nums2[j++];
            }
        }
        return total%2!=0?second:(first+second)/2.0;
    }
};