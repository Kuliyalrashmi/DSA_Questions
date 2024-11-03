class Solution {
public:
    bool rotateString(string s, string goal) {
        int m=s.size(),n=goal.size();
        if(m!=n)
        {
            return false;
        }
        if(s==goal)
        {
            return true;
        }
        queue<char>q1,q2;
        for(int i=0;i<m;i++)
        {
            q1.push(s[i]);
            q2.push(goal[i]);
        }
        while(n>=0)
        {
            char no=q1.front();
            cout<<no<<endl;
            q1.pop();
            q1.push(no);
            if(q1==q2)
            {
                return true;
            }
            n--;
        }
        return false;
    }
};