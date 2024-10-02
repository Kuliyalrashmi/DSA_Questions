class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp(arr.begin(),arr.end());
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        int rank=1,n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(arr[i])!=mp.end())
            {
                continue;
            }
            mp[arr[i]]=rank;
            rank++;
        }
        for(int j=0;j<n;j++)
        {
            temp[j]=mp[temp[j]];
        }
        return temp;
    }
};