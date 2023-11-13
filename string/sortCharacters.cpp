/* Leetcode Question no 451 Sort Characters By frequency 
Given a string s, sort it in decreasing order based on the frequency of the characters.
The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.
*/
class Solution {
public:
    static bool cmp(pair<int,char>a,pair<int,char>b)
    {
        return a.first>b.first;
    }
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        string ans;
        vector<pair<int,char>>p;
        for(auto i:mp)
        {
            p.push_back({i.second,i.first});
        }
        sort(p.begin(),p.end(),cmp);
        for(auto i:p)
        {
            int x=i.first;
            while(x--)
            {
                ans+=i.second;
            }
        }
        return ans;
    }
};
