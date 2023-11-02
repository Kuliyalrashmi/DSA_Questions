/* Longest Subarray With Sum K
Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
*/
/*Approach 1*/
#include <bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
  int len = 0, max_len = INT_MIN;
  int n = a.size();
  for (int i = 0; i < n; i++) {
     long long sum = 0;
    for (int j = i; j < n; j++) {
      sum += a[j];
      if (sum == k) {
        max_len = max((j-i+1), max_len);
      }
    }
  }
  return max_len;
}


/*Approach 2*/
#include <bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
  int n=a.size();
  int left=0,right=0,max_len=0;
  long long sum=a[0];
  while(right<n)
  {
    while(left<=right&&sum>k)
    {
      sum-=a[left];
      left++;
    }
    if(sum==k)
    {
      max_len=max(max_len,right-left+1);
    }
    right++;
    if(right<n)
    {
      sum+=a[right];
    }
  }
  return max_len;
}

