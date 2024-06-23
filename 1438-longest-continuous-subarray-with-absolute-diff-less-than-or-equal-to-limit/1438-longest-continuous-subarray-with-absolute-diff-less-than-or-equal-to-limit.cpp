class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int end=0,start=0,n=nums.size();
        int ans=0;
        multiset<int>mp;
        while(end<n)
        {
            mp.insert(nums[end]);
            int max_element=*mp.rbegin();
            int min_element=*mp.begin();
            while((max_element-min_element)>limit)
            {
                mp.erase(mp.find(nums[start]));
                start++;
                max_element=*mp.rbegin();
                min_element=*mp.begin();
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};