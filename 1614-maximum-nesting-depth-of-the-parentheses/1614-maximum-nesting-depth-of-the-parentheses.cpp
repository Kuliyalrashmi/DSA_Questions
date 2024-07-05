class Solution {
public:
    int maxDepth(string s) {
      int depth=0,ans=0;
      for(auto i:s)
      {
          if(i=='(')
          {
              depth++;
              ans=max(ans,depth);
          }
          else if(i==')')
          {
              depth--;
          }
      }
      return ans;
    }
};