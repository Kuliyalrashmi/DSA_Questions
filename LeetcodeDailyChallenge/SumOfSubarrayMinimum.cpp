/*   20-Jan-2024
Leetcode Question no 907 Sum of Subarray Minimum
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
Since the answer may be large, return the answer modulo 109 + 7.

*/

class Solution {
public:
    vector<int>NextSmallLeft(vector<int>&arr,int n)
    {
        vector<int>indices(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                indices[i]=-1;
            }
            else
            {
                while(!st.empty()&&arr[st.top()]>arr[i])
                {
                    st.pop();
                }
                indices[i]=st.empty()?-1:st.top();
            }
            st.push(i);
        }
        return indices;
    }
    vector<int>NextSmallright(vector<int>&arr,int n)
    {
        vector<int>indices(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                indices[i]=n;
            }
            else
            {
                while(!st.empty()&&arr[st.top()]>=arr[i])
                {
                    st.pop();
                }
                indices[i]=st.empty()?n:st.top();
            }
            st.push(i);
        }
        return indices;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>NSL=NextSmallLeft(arr,n);
        vector<int>NSR=NextSmallright(arr,n);
        long long int sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            long long int d1=i-NSL[i];
            long long int d2=NSR[i]-i;
            long long int ways=d1*d2;
            long long int sumi=arr[i]*ways;
            sum=(sum+sumi)%mod;
        }
        return sum;
    }
};
