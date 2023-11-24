/* Leetcode Question no 42 Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.
*/
class Solution {
public:
    int trap(vector<int>& height) {
       int left=INT_MIN,right=INT_MIN, start=0,end=height.size()-1,sum=0;
       while(start<end)
       {
           left=max(left,height[start]);
           right=max(right,height[end]);
           if(left<right)
           {
               sum+=(left-height[start]);
               start++;
           }
           else
           {
               sum+=right-height[end];
               end--;
           }
       }
       return sum;
    }
};
