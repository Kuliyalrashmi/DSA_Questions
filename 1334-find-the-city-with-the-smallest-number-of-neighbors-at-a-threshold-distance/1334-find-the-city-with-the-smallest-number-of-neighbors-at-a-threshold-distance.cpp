class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            distance[i][i]=0;
        }
        for(auto edge:edges)
        {
            distance[edge[0]][edge[1]]=edge[2];
            distance[edge[1]][edge[0]]=edge[2];
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if (distance[i][k] < INT_MAX && distance[k][j] < INT_MAX)
                    {
                        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                    }
                }
            }
        }
        int count_city=INT_MAX,ans=0;
        for(int i=n-1;i>=0;i--)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(distance[i][j]<=distanceThreshold&&i!=j)
                {
                    cnt++;
                }
            }
            if(cnt<count_city)
            {
                ans=i;
                count_city=cnt;
            }
        }
        return ans;
    }
};