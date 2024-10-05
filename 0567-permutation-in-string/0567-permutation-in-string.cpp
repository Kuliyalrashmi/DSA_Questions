class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      unordered_map<char,int>mp;
      for(auto i:s1)
      {
        mp[i]++;
      }  
      int count=mp.size();
      int start=0,end=0,n=s2.size();
      while(end<n)
      {
        if(mp.find(s2[end])!=mp.end())
        {
            mp[s2[end]]--;
            count-=(mp[s2[end]]==0);
        }
        while(count==0)
        {
            if(end-start+1==s1.size())
            {
                return true;
            }
            if(mp.find(s2[start])!=mp.end())
            {
                mp[s2[start]]++;
                count+=(mp[s2[start]]==1);
            }
            start++;
        }
        end++;
      }
      return false;
    }
};