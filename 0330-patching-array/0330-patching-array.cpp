class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum=0,i=0,count=0,size=nums.size();
        while(sum<n)
        {
            if(i<size&&nums[i]<=sum+1)
            {
                sum+=nums[i];
                i++;
            }
            else
            {
                sum+=(sum+1);
                count++;
            }
        }
        return count;
    }
};