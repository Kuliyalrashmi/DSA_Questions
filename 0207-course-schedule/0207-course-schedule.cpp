class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adj;
        int n=prerequisites.size();
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>indegree(numCourses,0);
        vector<int>visited(numCourses,0);
        vector<int>order;
        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
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
            order.push_back(front);
            for(auto it:adj[front])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return order.size()==numCourses;
    }
};