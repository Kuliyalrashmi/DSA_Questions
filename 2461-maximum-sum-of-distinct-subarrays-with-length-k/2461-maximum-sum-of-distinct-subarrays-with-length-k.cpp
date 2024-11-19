class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0,end=0;
        long long sum=0,max_sum=0;
        unordered_map<int,int>mp;
        while(end<n)
        {
           sum+=nums[end];
           mp[nums[end]]++;
           while(mp.size()>k||mp[nums[end]]>1)
           {
              mp[nums[start]]--;
              if(mp[nums[start]]==0)
              {
                mp.erase(nums[start]);
              }
              sum-=nums[start];
              start++;
           }
           if(end-start+1==k)
           {
            //  cout<<sum<<endl;
             max_sum=max(sum,max_sum);
           }
           end++;
        }
        return max_sum;
    }
};