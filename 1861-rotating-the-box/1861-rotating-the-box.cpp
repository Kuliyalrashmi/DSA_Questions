class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size(),n=box[0].size();
        vector<vector<char>>ans(n,vector<char>(m));
         for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        for(int j=0;j<m;j++)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(ans[i][j]=='.')
                {
                    int stoner=-1;
                    for(int k=i-1;k>=0;k--)
                    {
                        if(ans[k][j]=='*')
                        {
                            break;
                        }
                        else if(ans[k][j]=='#')
                        {
                            stoner=k;
                            break;
                        }
                    }
                    if(stoner!=-1)
                    {
                        ans[i][j]='#';
                        ans[stoner][j]='.';
                    }
                }
            }
        }
        return ans;
    }
};