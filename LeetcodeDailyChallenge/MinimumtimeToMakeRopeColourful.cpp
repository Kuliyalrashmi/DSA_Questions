/*  27-Dec-2023
Leetcode Question no 1578 Minimum Time To Make Rope Colourful

Alice has n balloons arranged on a rope. You are given a 0-indexed string colors 
where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, 
so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful.
You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds)
that Bob needs to remove the ith balloon from the rope.
  
Return the minimum time Bob needs to make the rope colorful.
*/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int cost=0;
        for(int i=1;i<n;i++)
        {
            if(colors[i-1]==colors[i])
            {
                cost+=min(neededTime[i],neededTime[i-1]);
                neededTime[i]=max(neededTime[i],neededTime[i-1]);
            }
        }
        return cost;
    }
};
