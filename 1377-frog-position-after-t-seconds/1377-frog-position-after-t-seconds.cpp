class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int,vector<int>>adj;
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<double>prob(n+1,0.0);
        vector<int>visited(n+1,0);
        queue<int>q;
        q.push(1);
        visited[1]=1;
        prob[1]=1.0;
        while(!q.empty()&&t--)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int front=q.front();
                q.pop();
                int count=0;
                for(auto neigh:adj[front])
                {
                  if(!visited[neigh])
                  {
                     count++;
                  }
                }
                for(auto neigh:adj[front])
                {
                   if(!visited[neigh])
                   {
                     q.push(neigh);
                     visited[neigh]=1;
                     prob[neigh]=prob[front]/count;
                   }
               }
              if(count>0)
              {
                prob[front]=0;
              }
            }
        }
        return prob[target];
    }
};