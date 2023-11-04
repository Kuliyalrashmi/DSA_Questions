/* Letcode Question no 38 Count And Say
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" 
  the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, 
split it into the minimal number of substrings such that each substring contains exactly one unique digit. 
Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.
*/
string countAndSay(int n) {
        if (n==1)
        {
            return "1";
        }
        string say=countAndSay(n-1);
        string ans="";
        for(int i=0;i<say.length();i++)
        {
            char ch=say[i];
            int count=1;
            while(i<say.size()&&say[i]==say[i+1])
            {
                count++;
                i++;
            }
            ans+=to_string(count)+string(1,ch);
        }
        return ans;
    }
