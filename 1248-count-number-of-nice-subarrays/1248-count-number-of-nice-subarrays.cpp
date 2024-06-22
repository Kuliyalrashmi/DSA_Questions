class Solution {
public:
    int solve(vector<int>&nums,int k)
    {
        int count=0,start=0,n=nums.size(),end=0,ans=0;
        while(end<n)
        {
            if(nums[end]%2==1)
            {
                count++;
            }
            while(count>k)
            {
                if(nums[start]%2==1)
                {
                   count--; 
                }
                start++; 
            }
            ans+=(end-start+1);
            end++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return (solve(nums,k)-solve(nums,k-1));
    }
};