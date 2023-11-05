/* Leetcode Question 15 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that
i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/

/*Approach 1 using Set*/
vector<vector<int>> triplet(int n, vector<int> &nums) {
  sort(nums.begin(), nums.end());
  vector<int> temp;
  int j, k;
  set<vector<int>> answer;
  for (int i = 0; i <= n; i++) {
    j = i + 1;
    k = n - 1;
    while (j < k) {
      int ans = nums[i] + nums[j] + nums[k];
      if (ans == 0) {
        temp.push_back(nums[i]);
        temp.push_back(nums[j]);
        temp.push_back(nums[k]);
        answer.insert(temp);
        temp.clear();
        j++;
        k--;
      } else if (ans > 0) {
        k--;
      } else {
        j++;
      }
    }
  }
  vector<vector<int>> output;
  copy(answer.begin(), answer.end(), inserter(output, output.begin()));
  return output;
}

/*Approach 2 Without using by handelling the duplicates*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
            int target=-nums[i];
            int start=i+1,end=n-1;
            while(start<end)
            {
                if(nums[start]+nums[end]==target)
                {
                    ans.push_back({nums[i],nums[start],nums[end]});
                while(start<end&&nums[start]==nums[start+1])
                {
                    start++;
                }
                while(start<end&&nums[end]==nums[end-1])
                {
                    end--;
                }
                start++;
                end--;
                }
                else if(nums[start]+nums[end]>target)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
        return ans;
    }
};
