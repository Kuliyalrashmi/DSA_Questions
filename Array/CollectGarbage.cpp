/* Leetcode Question No 2391 Minimum Amount Of Time To Collect Garbage
You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house.
garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively.
Picking up one unit of any type of garbage takes 1 minute.
You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.

There are three garbage trucks in the city, each responsible for picking up one type of garbage.
Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.

Only one garbage truck may be used at any given moment. While one truck is driving or picking up garbage, 
the other two trucks cannot do anything.

Return the minimum number of minutes needed to pick up all the garbage

*/

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time=0,n=garbage.size();
        int G=0,P=0,M=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<garbage[i].length();j++)
            {
                if(garbage[i][j]=='M')
                {
                    M=i;
                    time++;
                }
                else if(garbage[i][j]=='P')
                {
                    P=i;
                    time++;
                }
                else
                {
                    G=i;
                    time++;
                }
            }
        }
        int m=travel.size();
        for(int i=1;i<m;i++)
        {
            travel[i]+=travel[i-1];
        }
        if(M>0)
        {
            time+=travel[M-1];
        }
        if(P>0)
        {
            time+=travel[P-1];
        }
        if(G>0)
        {
            time+=travel[G-1];
        }
        return time;
    }
};
