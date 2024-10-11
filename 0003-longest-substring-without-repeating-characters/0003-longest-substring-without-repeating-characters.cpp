class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int max_len=0,start=0,end=0,n=s.size();
        while(end<n)
        {
            mp[s[end]]++;
            while(mp[s[end]]==2)
            {
                mp[s[start]]--;
                start++;
            }
            max_len=max(max_len,end-start+1);
            end++;
        }
        return max_len;
    }
};