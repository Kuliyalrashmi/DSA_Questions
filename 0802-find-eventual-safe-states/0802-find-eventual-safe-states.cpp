class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        map<int,vector<int>>mp;
        int n=graph.size();
        vector<int>ans;
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                mp[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto neigh:mp[front])
            {
                indegree[neigh]--;
                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};