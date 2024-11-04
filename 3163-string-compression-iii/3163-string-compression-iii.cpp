class Solution {
public:
    string compressedString(string word) {
       string ans="";
       int n=word.size();
       for(int i=0;i<n;i++)
       {
           char ch=word[i];
           int count=1;
           while(i+1<n&&ch==word[i+1]&&count<9)
           {
               count++;
               i++;
           }
           ans+=to_string(count);
           ans+=ch;
       }
       return ans;
    }
};