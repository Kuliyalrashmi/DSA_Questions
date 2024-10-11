class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)
        {
            return true;
        }
        else if(n<3)
        {
            return false;
        }
        while(n!=0&&n%3==0)
        {
            if(n!=3)
            {
                n=n/3;
            }
            else
            {
                n=0;
            }
        }
        return n==0;
    }
};