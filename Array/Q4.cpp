/* Leetcode 169 MAjority Element
Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. 
You may consider that such an element always exists in the array.
*/
/*Approach 1*/
int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto i:mp)
        {
            if(i.second>floor(n/2))
            {
                return i.first;
            }
        }
        return -1;
    }

/*Approach 2*/
#include<bits/stdc++.h>
int majorityElement(vector<int> v) {
	int count=1,element=0,n=v.size();
	for(int i=1;i<n;i++)
	{
		if(v[i]==v[element])
		{
			count++;
		}
		else
		{
			count--;
		}
		if(count==0)
		{
			element=i;
			count=1;
		}
	}
	return v[element];
}
