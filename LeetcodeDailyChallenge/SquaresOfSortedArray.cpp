/* 2-March-2024
  Given an integer array nums sorted in non-decreasing order, 
  return an array of the squares of each number sorted in non-decreasing order.
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=nums.size()-1,k=nums.size()-1;
        vector<int>ans(nums.size());
        while(i<=j)
        {
            if(abs(nums[i])>abs(nums[j]))
            {
                ans[k--]=nums[i]*nums[i];
                i++;
            }
            else
            {
                ans[k--]=nums[j]*nums[j];
                j--;
            }
        }
        return ans;
    }
};
