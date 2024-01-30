/*   30-Jan-2024
Leetcode Question no 150 Evaluate Reverse Polish Notation
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int>temp;
       int n=tokens.size(),z=0;
       for(int i=0;i<n;i++)
       {
           if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
           {
               int no=(stoi(tokens[i]));
               temp.push(no);
           }
           else
           {
               int x=temp.top();
               temp.pop();
               int y=temp.top();
               temp.pop();
               if(tokens[i]=="+")
               {
                   z=x+y;
               }
               else if(tokens[i]=="-")
               {
                   z=y-x;
               }
               else if(tokens[i]=="*")
               {
                   z=x*y;
               }
               else if(tokens[i]=="/")
               {
                   z=y/x;
               }
               temp.push(z);
           }
       } 
       return temp.top();
    }
};
