/*  
Leetcode Question no 2974 Minimum Number Game

You are given a 0-indexed integer array nums of even length and there is also an empty array arr. 
Alice and Bob decided to play a game where in every round Alice and Bob will do one move. 
The rules of the game are as follows:
Every round, first Alice will remove the minimum element from nums, and then Bob does the same.
Now, first Bob will append the removed element in the array arr, and then Alice does the same.
The game continues until nums becomes empty.
Return the resulting array arr.

*/

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        vector<int>ans;
        while(!pq.empty())
        {
            int alice=pq.top();
            pq.pop();
            int bob=pq.top();
            pq.pop();
            ans.push_back(bob);
            ans.push_back(alice);
        }
        return ans;
    }
};
