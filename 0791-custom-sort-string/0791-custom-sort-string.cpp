class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>hash(26,0);
        string ans="";
        for(auto i:s)
        {
            hash[i-'a']++;
        }
        for(auto i:order)
        {
            while(hash[i-'a']>0)
            {
                ans.push_back(i);
                hash[i-'a']--;
            }
        }
        for(auto i:s)
        {
            if(hash[i-'a']>0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};