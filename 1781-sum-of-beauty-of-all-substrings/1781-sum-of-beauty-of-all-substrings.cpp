class Solution {
public:
    int beautySum(string s) {
      int n=s.size(),ans=0;
      for(int i=0;i<n;i++)
      {
          unordered_map<char,int>mp;
          for(int j=i;j<n;j++)
          {
              mp[s[j]]++;
              int maxi=INT_MIN;
              int mini=INT_MAX;
              for(auto i:mp)
              {
                  if(i.second>maxi)
                  {
                      maxi=i.second;
                  }
                  if(i.second<mini)
                  {
                      mini=i.second;
                  }
              }
              ans+=(maxi-mini);
          }
      }
      return ans;
    }
};