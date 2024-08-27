class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];
        int size=edges.size();
        for(int i=0;i<size;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>prob(n,0.0);
        queue<pair<int,double>>pq;
        prob[start_node]=1.0;
        pq.push({start_node,1.0});
        while(!pq.empty())
        {
            auto front=pq.front();
            pq.pop();
            for(auto neigh:adj[front.first])
            {
                 if(prob[neigh.first]<(front.second*neigh.second)){
                    prob[neigh.first]=front.second*neigh.second;
                    pq.push({neigh.first,prob[neigh.first]});
                }
            }
        }
        return prob[end_node];
    }
};