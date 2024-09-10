class Solution {
public:
    int find(int a,vector<int>&parent)
    {
        if(a==parent[a])
        {
            return a;
        }
        return parent[a]=find(parent[a],parent);
    }
    bool unioni(int a,int b,vector<int>&parent)
    {
        a=find(a,parent);
        b=find(b,parent);
        if(a==b)
        {
            return false;
        }
        parent[b]=a;
        return true;
    }
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        vector<int>parent(n);
        int ans=0;
        for(int i=0;i<n;i+=2)
        {
            parent[row[i]]=row[i];
            parent[row[i+1]]=row[i];
        }
        for(int i=0;i<n;i+=2)
        {
            if(unioni(i,i+1,parent))
            {
                ans++;
            }
        }
        return ans;
    }
};