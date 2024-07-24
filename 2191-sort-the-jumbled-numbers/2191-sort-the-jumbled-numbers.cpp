class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.first<b.first;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
       vector<pair<int,int>>vp;
       for(auto i:nums)
       {
           int temp=i;
           int num=0;
           int place=1;
           if(i==0)
           {
               num=mapping[i];
           }
           else
           {
               while(temp)
           {
               num=num+(mapping[temp%10]*place);
               temp=temp/10;
               place=place*10;
           }
           }
           vp.push_back({num,i});
       }
        sort(vp.begin(),vp.end(),comp);
        vector<int>ans;
        for(auto i:vp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};