class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans=0;
        long long sum=0;
        unordered_map<int,int>mp;
        for(auto i:banned)
        {
            mp[i]=1;
        }
        int i;
        for(i=1;i<=n;i++)
        {
            if(mp.find(i)!=mp.end())
            {
                continue;
            }
            sum+=i;
            if(sum>maxSum)
            {
                break;
            }
            ans++;
        }
        return ans;
    }
};