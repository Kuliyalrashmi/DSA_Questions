class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int size=nums.size();
        sort(nums.begin(),nums.end());
        int median=nums[size/2];
        int steps=0;
        for(int i=0;i<size;i++)
        {
            steps+=(abs(median-nums[i]));
        }
        return steps;
    }
};