/* 10-Mar-2024
Leetcode Question no 349 Intersection OF Two Arrays
Given two integer arrays nums1 and nums2,
return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>output;
        set<int>temp;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0,k=0;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                i++;
            }
            else if(nums1[i]>nums2[j])
            {
                j++;
            }
            else
            {   temp.insert(nums1[i]);
                i++;
                j++;
            }
            
        }
        for(auto i:temp) 
        {
            output.push_back(i);
        }
        return output;
    }
};

 
