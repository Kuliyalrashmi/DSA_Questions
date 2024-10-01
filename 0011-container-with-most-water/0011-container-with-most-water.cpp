class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int start=0,end=height.size()-1;
        while(start<end)
        {
            if(height[start]<height[end])
            {
                int area=(end-start)*height[start];
                ans=max(ans,area);
                start++;
            }
            else
            {
                
                int area=(end-start)*height[end];
                ans=max(ans,area);
                end--;
            }
        }
        return ans;
    }
};