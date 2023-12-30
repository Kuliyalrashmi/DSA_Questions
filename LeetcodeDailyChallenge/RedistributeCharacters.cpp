/*   30-Dec-2023
Leetcode Question no Redistribute Characters To Make All Srings Equal

You are given an array of strings words (0-indexed).
In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, 
and move any character from words[i] to any position in words[j].
Return true if you can make every string in words equal using any number of operations, and false otherwise.

*/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.size()==1)
        {
            return true;
        }
        int totalChar=0;
        for(auto i:words)
        {
            totalChar+=i.size();
        }
        int n=words.size();
        if(totalChar%n!=0)
        {
            return false;
        }
        unordered_map<char,int>mp;
        for(auto i:words)
        {
            for(auto j:i)
            {
                mp[j]++;
            }
        }
        for(auto i:mp)
        {
            if(i.second%n!=0)
            {
                return false;
            }
        }
        return true;
    }
};
