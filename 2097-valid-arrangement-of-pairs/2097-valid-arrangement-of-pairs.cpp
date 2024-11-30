class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>indegree,outdegree;
        for(auto nodes:pairs)
        {
            int u=nodes[0],v=nodes[1];
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }
        
        int start=pairs[0][0];
        for(auto edge:adj)
        {
            int node=edge.first;
            if(outdegree[node]-indegree[node]==1)
            {
                start=node;
                break;
            }
        }
        vector<int>path;
        stack<int>st;
        st.push(start);
        while(!st.empty())
        {
            int curr=st.top();
            if(!adj[curr].empty())
            {
                int nei=adj[curr].back();
                adj[curr].pop_back();
                st.push(nei);
            }
            else
            {
                path.push_back(curr);
                st.pop();
            }
        }
        reverse(path.begin(),path.end());
        vector<vector<int>>ans;
        for(int i=0;i<path.size()-1;i++)
        {
            ans.push_back({path[i],path[i+1]});
        }
        return ans;
    }
};