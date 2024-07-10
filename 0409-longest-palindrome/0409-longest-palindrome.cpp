class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        if(mp.size()==1)
        {
            return s.size();
        }
        int count=0,odd=0;
        for(auto i:mp)
        {
            if(i.second>=2)
            {
                count+=(i.second/2)*2;
                i.second-=(i.second/2)*2;
            }
            if(i.second==1)
            {
                odd=1;
            }
        }
        return (count+odd);
    }
};