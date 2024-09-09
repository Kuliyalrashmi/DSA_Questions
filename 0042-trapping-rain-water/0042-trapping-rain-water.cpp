class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n),right(n);
        int max_ele=INT_MIN;
        for(int i=0;i<n;i++)
        {
            max_ele=max(max_ele,height[i]);
            left[i]=max_ele;
        }
        max_ele=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            max_ele=max(max_ele,height[i]);
            right[i]=max_ele;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
};