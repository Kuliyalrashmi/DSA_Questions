class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++)
        {   
            int p=arr[i]*2;
            for(int j=0;j<n;j++)
            {
                if(arr[j]==p&&i!=j)
                {
                    return true;
                }
            }
        }
        return false;
    }
};