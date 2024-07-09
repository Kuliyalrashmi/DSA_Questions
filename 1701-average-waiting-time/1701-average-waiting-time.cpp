class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int current_time=0;
        double avg_wait=0;
        int n=customers.size();
        for(int i=0;i<n;i++)
        {
            int arrival=customers[i][0];
            int preparing=customers[i][1];
            if(current_time<arrival)
            {
                current_time=arrival;
            }
            int time=current_time-arrival+preparing;
            avg_wait+=time;
            current_time+=preparing;
        }
        return (avg_wait)/n;
    }
};