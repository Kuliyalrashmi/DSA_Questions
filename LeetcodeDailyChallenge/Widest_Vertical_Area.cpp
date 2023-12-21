/*   21-Dec-2023
Leetcode Question no 1637 Widest Vertical Area Between Two Points Containing No Points
Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that 
no points are inside the area.
A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height).
The widest vertical area is the one with the maximum width.
Note that points on the edge of a vertical area are not considered included in the area.
*/

/* Approach  Using Sorting */
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size(),max_dist=INT_MIN;
        int diff;
        for(int i=0;i<n-1;i++)
        {
            diff=points[i+1][0]-points[i][0];
            max_dist=max(max_dist,diff);
        }
        return max_dist;
    }
};


