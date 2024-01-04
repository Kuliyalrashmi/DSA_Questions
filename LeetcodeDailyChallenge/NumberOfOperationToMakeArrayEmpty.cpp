/*   4-Jan-2024
  
Leetcode Question no 2870 Minimum Number Of Operations To MAke Array Empty

You are given a 0-indexed array nums consisting of positive integers.

There are two types of operations that you can apply on the array any number of times:

Choose two elements with equal values and delete them from the array.
Choose three elements with equal values and delete them from the array.
Return the minimum number of operations required to make the array empty, or -1 if it is not possible.

*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
       unordered_map<int,int>mp;
       for(auto i:nums)
       {
           mp[i]++;
       }           
       int ans=0;
       for(auto x:mp)
       {
           int j=x.second;
           if(j==1)
           {
               return -1;
           }
           ans+=(j+2)/3;
       }  
       return ans;
    }
};

 
