/*  24 Feb 2024
LEetcode Question no 2092 Find All People With Secret
You are given an integer n indicating there are n people numbered from 0 to n - 1. 
  You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] 
  indicates that person xi and person yi have a meeting at timei. 
A person may attend multiple meetings at the same time. 
Finally, you are given an integer firstPerson.

Person 0 has a secret and initially shares the secret with a person firstPerson at time 0.
  This secret is then shared every time a meeting takes place with a person that has the secret. 
  More formally, for every meeting, if a person xi has the secret at timei, 
  then they will share the secret with person yi, and vice versa.

The secrets are shared instantaneously. 
  That is, a person may receive the secret and share it 
with people in other meetings within the same time frame.

Return a list of all the people that have the secret after all the meetings have taken place. 
  You may return the answer in any order.

*/

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
         unordered_map<int, vector<pair<int,int>>> adj;
        
        for(vector<int>& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time    = meeting[2];
            
            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }
        
        queue<pair<int,int>> que;
        que.push({0, 0});
        que.push({firstPerson, 0});
        vector<int> earlySecretTime(n, INT_MAX);
        earlySecretTime[0] = 0;
        earlySecretTime[firstPerson] = 0;
        
        while(!que.empty()) {
            auto [person, time] = que.front();
            
            que.pop();
            
            for(auto& ngbr : adj[person]) {
                int nextPerson = ngbr.first;
                int t          = ngbr.second;
                
                if(t >= time && earlySecretTime[nextPerson] > t) {
                    earlySecretTime[nextPerson] = t;
                    que.push({nextPerson, t});
                }
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(earlySecretTime[i] != INT_MAX) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};

 
