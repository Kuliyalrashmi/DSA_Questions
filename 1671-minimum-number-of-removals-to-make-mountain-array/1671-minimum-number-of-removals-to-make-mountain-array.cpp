class Solution {
public:
    void lengthOfLIS(vector<int>& nums,vector<int> &LIS)
    {
        vector<int> arr;
        
        arr.push_back(nums[0]);
        LIS.push_back(1);
        
        for(int i = 1 ; i<nums.size() ; i++)
        {
            if(nums[i] > arr.back())
                arr.push_back(nums[i]);
            else
            {
               auto index = lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin() ;
               arr[index] = nums[i];
            }
            LIS.push_back(max((int)(arr.size()), LIS.back()));
         
        }
    }
    void lengthOfLDS(vector<int>& nums,vector<int> &LDS)
    {
        vector<int> arr;
        
        arr.push_back(nums.back());
        LDS.push_back(0);
        LDS.push_back(1);
        
        for(int i=nums.size()-2 ;  i >= 0 ; i--)
        {
            if(nums[i] > arr.back())
                arr.push_back(nums[i]);
            else
            {
               auto index = lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin() ;
               arr[index] = nums[i];
            }
            LDS.push_back(max((int)(arr.size()), LDS.back()));
         
        }
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> LIS, LDS;

        lengthOfLIS(nums, LIS);
        lengthOfLDS(nums, LDS);
        reverse(LDS.begin(), LDS.end());
        for(int i = 1 ; i<n-1 ; i++){
            if(LIS[i]>1 && LDS[i]>1)
            ans = max(LIS[i]+LDS[i]-1, ans);
            
        }

        return n-ans;
    }
};