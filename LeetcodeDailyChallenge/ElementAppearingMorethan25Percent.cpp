/*   12-Dec-2023
Leetcode Questiong no 1287 Element Appearing More than 25% In Sorted Array
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs 
more than 25% of the time, return that integer.
*/
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size(),count=1;
        int limit=(0.25)*n;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]==arr[i+1])
            {
                count++;
            }
            if(count>limit)
            {
                return arr[i];
            }
            if(arr[i]!=arr[i+1])
            {
                count=1;
            }
        }
        return count;
    }
};
