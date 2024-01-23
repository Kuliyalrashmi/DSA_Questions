/*  23-Jan-2024
Leetcode Question no 1239 MAximum Length Of Concatenated String With Unique String
You are given an array of strings arr. A string s is formed by the 
concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without
changing the order of the remaining elements.

*/

class Solution {
public:
    bool hasCommon(string &s1,string &s2)
    {
        int arr[26]={0};
        for(char&ch:s1)
        {
            if(arr[ch-'a']>0)
            {
                return true;
            }
            arr[ch-'a']++;
        }
        for(char&ch:s2)
        {
            if(arr[ch-'a']>0)
            {
                return true;
            }
        }
       return false;
    }
    int solve(int index,vector<string>&arr,string temp,int n,unordered_map<string,int>&mp)
    {
        if(index>=n)
        {
            return temp.size();
        }
        if(mp.find(temp)!=mp.end())
        {
            return mp[temp];
        }
        int include=0,exclude=0;
        string value=arr[index];
        if(hasCommon(value,temp))
        {
            exclude=solve(index+1,arr,temp,n,mp);
        }
        else
        {
            exclude=solve(index+1,arr,temp,n,mp);
            temp+=arr[index];
            include=solve(index+1,arr,temp,n,mp);
        }
        return mp[temp]=max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        string temp="";
        unordered_map<string,int>mp;
        int n=arr.size();
        return solve(0,arr,temp,n,mp);
    }
};
