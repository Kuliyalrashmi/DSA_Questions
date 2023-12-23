/*      23-Dec-2023
  
Leetcode Question no 1496 Path Crossing
Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, 
south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.
Return true if the path crosses itself at any point, that is,
if at any time you are on a location you have previously visited. Return false otherwise.

*/


/* Approch Using unordered map */
class Solution {
public:
    bool isPathCrossing(string path) {
        int i=0,j=0;
        map<pair<int,int>,int>mp;
        mp[{i,j}]=1;
        int n=path.size();
        for(int k=0;k<n;k++)
        {
            if(path[k]=='E')
            {
                i++;
            }
            else if(path[k]=='W')
            {
                i--;
            }
            else if(path[k]=='N')
            {
               j++;
            }
            else
            {
                j--;
            }
            if(mp.find({i,j})!=mp.end())
            {
                return true;
            }
            mp[{i,j}]=1;
        }
        return false;
    }
};
