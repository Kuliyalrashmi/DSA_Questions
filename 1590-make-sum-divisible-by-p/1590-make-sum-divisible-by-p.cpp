class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        int rem = sum % p;
        if (rem == 0) {
            return 0;
        }
        unordered_map<int, int> mp;
        mp[0] = -1; 
        int prefix_sum = 0;
        int n = nums.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            int remain = (prefix_sum - rem + p) % p;

            if (mp.find(remain) != mp.end()) {
                ans = min(ans, i - mp[remain]);
            }

            mp[prefix_sum] = i;
        }
        return ans == n ? -1 : ans;
    }
};
