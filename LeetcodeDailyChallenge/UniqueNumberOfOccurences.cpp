/*   17-Jan-2024
  
Leetcode Question no 1207 Unique Number Of Occurences
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique 
or false otherwise.

*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int,int>map;
      vector<pair<int,int>>temp;
       int n=arr.size();
       for(int i=0;i<n;i++)
       {
           map[arr[i]]++;
       }
       for(auto i:map)
       {
          temp.push_back({i.second,i.first});
       }
       sort(temp.begin(),temp.end());
       for(int i=0;i<temp.size()-1;i++)
       {
           if(temp[i].first==temp[i+1].first)
           {
               return false;
           }
       }
       return true;
    }
};
