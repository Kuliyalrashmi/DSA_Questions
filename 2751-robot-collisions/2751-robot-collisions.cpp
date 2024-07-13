class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int>index(n),ans;
        for(int i=0;i<n;i++)
        {
           index[i]=i;    
        }
        sort(index.begin(), index.end() , [&](int i, int j){
            return positions[i] < positions[j];
        });
        stack<int>st;
        for(int i:index)
        {
            if(directions[i]=='R')
            {
                st.push(i);
            }
            else
            {
                while(!st.empty()&&healths[i]>0)
                {
                    int top=st.top();
                    st.pop();
                    if(healths[top]>healths[i])
                    {
                        healths[top]--;
                        healths[i]=0;
                        st.push(top);
                    }
                    else if(healths[top]<healths[i])
                    {
                        healths[i]--;
                        healths[top]=0;
                    }
                    else
                    {
                        healths[i]=0;
                        healths[top]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(healths[i]>0)
            {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};