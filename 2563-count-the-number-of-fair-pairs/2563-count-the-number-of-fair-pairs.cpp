class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
       int n=nums.size();
       sort(nums.begin(),nums.end());
       long long ans=0;
       for(int i=0;i<n;i++)
       {
           int index=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
           int x=index-1-i;
           index=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
           int y=index-1-i;
           ans+=(y-x);
       }
       return ans;
    }
};