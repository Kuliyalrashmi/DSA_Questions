class Solution {
public:
    int passThePillow(int n, int time) {
       int total=time/(n-1);
       int left=time%(n-1);
        if(total%2==0)
        {
            return left+1;
        }
        else
        {
            return n-left;
        }
        return -1;
    }
};