/*  15-Dec-2023
  
Leetcode Question no 1436 Destination City
You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. 
Return the destination city, that is, the city without any path outgoing to another city.
It is guaranteed that the graph of paths forms a line without any loop,
therefore, there will be exactly one destination city.
*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>mp;
        int n=paths.size();
        for(int i=0;i<n;i++)
        {
            mp[paths[i][0]]++;
        }
        string curr="";
        for(int i=0;i<n;i++)
        {
            if(mp[paths[i][1]]<1)
            {
                curr+=paths[i][1];
            }
        }
        return curr;
    }
};
