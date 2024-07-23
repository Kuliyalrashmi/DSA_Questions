class Solution {
public:
  static bool comp(pair<int,int>p1,pair<int,int>p2)
  {
  if(p1.first==p2.first)
  {
  return p1.second>p2.second;
  }
  return p1.first<p2.first;
  }
vector<int> frequencySort(vector<int>& nums) {
            
        map<int,int>mp; 
       for(auto i:nums)
       {
           mp[i]++;
       }
        vector<pair<int,int>>temp;
        for(auto j:mp)
       {
           temp.push_back({j.second,j.first});
       }
       sort(temp.begin(),temp.end(),comp);
        nums.clear();
        for(auto j:temp)
       {
           int num=j.first;
           while(num>0)
           {
               nums.push_back(j.second);
               num--;
           }
       }
       return nums;
    }
};