class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int>ans(n,1);
        int m=rolls.size();
        int required_sum=mean*(n+m),sum=0;
        for(auto ele:rolls)
        {
            sum+=ele;
        }
        int missing_sum=required_sum-sum;
        if (missing_sum < n || missing_sum > n * 6) return {};
        missing_sum-=n;
        for(int i=0;i<n;i++)
        {
            ans[i]+=min(5,missing_sum);
            missing_sum-=min(5,missing_sum);
            if (missing_sum <= 0) break;
        }
        return ans;
    }
};