class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int start=0,end=0,n=s.size(),ans=0;
        while(end<n)
        {
            mp[s[end]]++;
            while(start<=end&&mp[s[end]]>1)
            {
                mp[s[start]]--;
                start++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};