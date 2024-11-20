class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size(),count_a=0,count_b=0,count_c=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                count_a++;
            }
            else if(s[i]=='b')
            {
                count_b++;
            }
            else
            {
                count_c++;
            }
        }
        if(count_a<k||count_b<k||count_c<k)
        {
            return -1;
        }
        int start=0,end=0,window=0;
        while(end<n)
        {
            if(s[end]=='a')
            {
                count_a--;
            }
            else if(s[end]=='b')
            {
                count_b--;
            }
            else
            {
                count_c--;
            }
            while(start<=end&&(count_a<k||count_b<k||count_c<k))
            {
                if(s[start]=='a')
                {
                    count_a++;
                }
                else if(s[start]=='b')
                {
                    count_b++;
                }
                else
                {
                    count_c++;
                }
                start++;
            }
            window=max(window,end-start+1);
            end++;
        }
        return n-window;
    }
};