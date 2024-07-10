class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        int n=prerequisites.size();
        vector<int>indegree(numCourses,0);
        vector<int>visited(numCourses,0);
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        queue<int>q;
        vector<int>order;
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
        if(order.size()==numCourses)
        {
            return true;
        }
        return false;
    }
};