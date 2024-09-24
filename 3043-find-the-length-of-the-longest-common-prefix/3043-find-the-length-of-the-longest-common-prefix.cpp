class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
       unordered_set<int>st;
       for(auto ele:arr1)
       {
         while(!st.count(ele)&&ele>0)
         {
            st.insert(ele);
            ele/=10;
         }
       }
       int ans=0;
       for(auto num:arr2)
       {
         while(!st.count(num)&&num>0)
         {
            num/=10;
         }
         if(num>0)
         {
            ans=max(ans,static_cast<int>(log10(num)) + 1);
         }
       }
       return ans;
    }
};