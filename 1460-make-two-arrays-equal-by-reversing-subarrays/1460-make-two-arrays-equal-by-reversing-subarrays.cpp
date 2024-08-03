class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>mp;
        int n=target.size();
        for(int i=0;i<n;i++)
        {
            mp[target[i]]++;
        }
        n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(arr[i])!=mp.end())
            {
                mp[arr[i]]--;
                if(mp[arr[i]]==0)
                {
                    mp.erase(arr[i]);
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};