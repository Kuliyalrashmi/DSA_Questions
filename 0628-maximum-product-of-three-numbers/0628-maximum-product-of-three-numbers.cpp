class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int max1=nums[0]*nums[1]*nums[n-1];
        int max2=nums[n-1]*nums[n-2]*nums[n-3];
        if(max1>max2)
        {
            return max1;
        }
        return max2;
    }
};