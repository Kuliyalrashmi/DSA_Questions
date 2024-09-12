class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n=words.size(),count=0,answer=0;
        unordered_map<int,bool>map;
        for(auto i : allowed)
        {
           map[i]=true;
        }
        for(auto i : words)
        {
            int n=i.length();
            string str=i;
            count=0;
            for(int j=0;j<n;j++)
            {
                if(map[str[j]]==true)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            if(count==n)
            {
               answer++;
            }
        }
        return answer;
    }
};