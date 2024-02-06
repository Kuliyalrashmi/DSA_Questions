/*  6-Feb-2024
Leetcode Question no 49 Group Anagrams
Given an array of strings strs, group the anagrams together.
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<int>>mp;
        int n=strs.size();
        for(int i=0;i<n;i++)
        {
            string str=strs[i];
            sort(str.begin(),str.end());
            mp[str].push_back(i);
        }
        for(auto i:mp)
        {
            vector<string>temp;
            for(int j=0;j<i.second.size();j++)
            {
                temp.push_back(strs[i.second[j]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
