/*  Turbulent Ranges

You have been given an array/list HEIGHT denoting the heights of ‘N’ adjacent hills.
The hills are said to be dangerous if their heights are turbulent.
A range of hills is turbulent if the comparison sign for their heights flips between each adjacent pair of hills. 
For example, if HEIGHT = [1, 2, 10, 3, 5, 1, 10, 10],
then the hills in index range [1, 6] are turbulent as 2 < 10 > 3 < 5 > 1 < 10.
Your task is to find the length of the longest dangerous hill range.
*/

#include <bits/stdc++.h> 
int longestDangerousRange(vector<int>& height, int n)
{   
   int flag=0,count=1,max_count=1;
   for(int i=1;i<n;i++)
   {
       if(height[i]>height[i-1] &&flag==0)
       {
           count++;
           max_count=max(count,max_count);
           flag=1;
       }
       else if(height[i-1]>height[i]&&flag==1)
       {
           count++;
           max_count=max(max_count,count);
           flag=0;
       }
       else if(height[i]>height[i-1])
       {
           count=2;
           max_count=max(count,max_count);
           flag=1;
       }
       else if(height[i]<height[i-1])
       {
           count=2;
           max_count=max(count,max_count);
           flag=0;
       }
       else
       {
           count=1;
       }
   }
   return max_count;
}
