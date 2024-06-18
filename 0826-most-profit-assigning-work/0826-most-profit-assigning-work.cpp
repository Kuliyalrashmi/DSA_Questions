class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m=worker.size(),n=difficulty.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)
        {
            int diff=difficulty[i];
            int pro=profit[i];
            pq.push({pro,diff});
        }
        sort(worker.begin(),worker.end(),greater<int>());
        int i=0,total_profit=0;
        while(i<m&&!pq.empty())
        {
            if(pq.top().second>worker[i])
            {
                pq.pop();
            }
            else
            {
                total_profit+=pq.top().first;
                i++;
            }
        }
        return total_profit;
    }
};