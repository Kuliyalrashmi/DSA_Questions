/*  7-Feb-2024
Leetcode Question no 451 Sort Characters by frequency
Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.
*/


/*  Using unordered_map and vector of pairs */
class Solution {
public:
    static bool cmp(pair<int,char>a,pair<int,char>b)
    {
        return a.first>b.first;
    }
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        vector<pair<int,char>>p;
        for(auto i:mp)
        {
            p.push_back({i.second,i.first});
        }
        sort(p.begin(),p.end(),cmp);
        string str="";
        for(auto i:p)
        {
            int x=i.first;
            while(x!=0)
            {
               str+=i.second;
               x--;
            }
        }
        return str;
    }
};


/*  Using Priority Queue */

class Solution {
public:
    // static bool cmp(pair<int,char>a,pair<int,char>b)
    // {
    //     return a.first>b.first;
    // }
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        string answer="";
        while(!pq.empty())
        {
           int no=pq.top().first;
           while(no)
           {
              answer+=pq.top().second;
              no--;
           }
           pq.pop();
        }
        return answer;
    }
};
