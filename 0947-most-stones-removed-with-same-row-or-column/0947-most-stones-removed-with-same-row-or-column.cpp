class Solution {
public:
    int solve(vector<vector<int>>& stones,vector<int>&visited,int src,int n)
    {
        queue<int>q;
        visited[src]=1;
        q.push(src);
        int count=0;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            for(int i=0;i<n;i++)
            {
                if(!visited[i])
                {
                    if(stones[i][0]==stones[front][0]||stones[i][1]==stones[front][1])
                    {
                        q.push(i);
                        visited[i]=1;
                        count++;
                    }
                }
            }
        }
        return count;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                ans+=solve(stones,visited,i ,n);
            }
        }
        return ans;
    }
};