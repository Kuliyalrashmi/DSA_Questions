class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n=heights.size();
       vector<int>left(n,0),right(n,n-1);
        stack<int>st1,st2;
        for(int i=0;i<n;i++)
        {
            while(!st1.empty()&&heights[st1.top()]>=heights[i])
            {
                st1.pop();
            }
            if(!st1.empty())
            {
                left[i]=st1.top()+1;
            }
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty()&&heights[st2.top()]>=heights[i])
            {
                st2.pop();
            }
            if(!st2.empty())
            {
                right[i]=st2.top()-1;
            }
            st2.push(i);
        }
        int max_area=0;
        for(int i=0;i<n;i++)
        {
            cout<<left[i]<<" "<<right[i]<<endl;
            int area=(right[i]-left[i]+1)*heights[i];
            max_area=max(area,max_area);
        }
        return max_area;
    }
};