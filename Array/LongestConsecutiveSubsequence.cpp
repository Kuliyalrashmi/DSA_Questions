/* Leetcode 123 Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
*/
 int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        int count=1,max_count=1;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:nums)
        {
            pq.push(i);
        }
        while(!pq.empty())
        {
            int top=pq.top();
            pq.pop();
            if(top+1==pq.top())
            {
                count++;
            }
            else if(top==pq.top())
            {
                continue;
            }
            else
            {
                max_count=max(count,max_count);
                count=1;
            }
        }
        return max(count,max_count);
    }

