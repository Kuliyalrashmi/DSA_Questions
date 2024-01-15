/*    15-Jan-2024
Leetcode Question no 2225 Find Players With Zero Or One Losses
You are given an integer array matches where matches[i] = [winneri, loseri] indicates that
the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.

*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>loosing;
        int n=matches.size();
        for(int i=0;i<n;i++)
        {
            loosing[matches[i][1]]++;
        }
        vector<int>temp_loose;
        set<int>st;
        for(int i=0;i<n;i++)
        {
            if(loosing.find(matches[i][0])==loosing.end())
            {
                st.insert(matches[i][0]);
            }
        }
        for(auto i:loosing)
        {
            if(i.second==1)
            {
                temp_loose.push_back(i.first);
            }
        }
        vector<int>temp_win(st.begin(),st.end());
        vector<vector<int>>ans;
        sort(temp_loose.begin(),temp_loose.end());
        ans.push_back(temp_win);
        ans.push_back(temp_loose);
        return ans;
    }
};
