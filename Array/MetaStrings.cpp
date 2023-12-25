/* 
You are given two strings 'STR1' and 'STR2'. You need to tell whether the strings are meta strings or not.
Meta strings are strings that can be made equal by swapping exactly one pair of distinct characters in one of the strings.
Note:
Equal strings are not considered as meta strings. 
*/

#include <bits/stdc++.h> 
bool checkMeta(string &str1, string &str2)
{
   int m=str1.size(),n=str2.size();
   if(m!=n||str1==str2)
   {
       return false;
   }
   int hash[26]={0};
   for(int i=0;i<m;i++)
   {
       hash[str1[i]-'a']++;
   }
   for(int i=0;i<n;i++)
   {
       hash[str2[i]-'a']--;
   }
   for(int i=0;i<26;i++)
   {
       if(hash[i]>0)
       {
           return false;
       }
   }
   return true;
}
