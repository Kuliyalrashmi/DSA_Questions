/*  8-MAr-2024
Leectode Question no 3005 Count Elements With MAximum Frequency
You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.
  */

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>arr(101);
        int max_freq=0;
        for(auto i:nums)
        {
            arr[i]++;
            max_freq=max(max_freq,arr[i]);
        }
        return count(arr.begin(),arr.end(),max_freq)*max_freq;
    }
};
