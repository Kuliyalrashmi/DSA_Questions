/*
Leetcode Question no 845 Longest Mountain In Array
You may recall that an array arr is a mountain array if and only if:
arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain.
Return 0 if there is no mountain subarray.
*/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int i=1,lower=0,upper=0;
        int maxi=0;
        while(i<n)
        {
            upper=0,lower=0;
            while(i<n&&arr[i]==arr[i-1])
            {
                i++;
            }
            while(i<n&&arr[i]>arr[i-1])
            {
                i++;
                upper++;
            }
            while(i<n&&arr[i]<arr[i-1])
            {
                i++;
                lower++;
            }
             if(upper&&lower)
            {
            maxi=max(lower+upper+1,maxi);
            }
        }
        return maxi;
    }
};

 
