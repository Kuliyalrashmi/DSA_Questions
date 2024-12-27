class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_score=INT_MIN;
        int n=values.size();
        int curr_max=values[0];
        for(int i=1;i<n;i++)
        {
            max_score=max(max_score,curr_max+values[i]-i);
            curr_max=max(curr_max,values[i]+i);
        }
        return max_score;
    }
};