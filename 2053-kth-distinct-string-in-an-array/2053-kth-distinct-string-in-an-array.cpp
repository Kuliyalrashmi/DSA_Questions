class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        for(auto i:arr)
        {
            mp[i]++;
        }
        for(auto i:arr)
        {
            auto it=mp.find(i);
            int count=it->second;
            if(count==1)
            {
                k--;
                if(k==0)
                {
                    return i;
                }
            }
        }
        return "";
    }
};