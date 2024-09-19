class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;
        int n=expression.size();
        for(int i = 0 ; i < n ; i++) {
            char ch = expression[i];

            if(ch == '+' || ch == '-' || ch == '*') {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);
                
                vector<int> Left = diffWaysToCompute(left);
                vector<int> Right = diffWaysToCompute(right);

                for(int  l : Left) {
                    for(int r : Right) {
                        if(ch == '+') {
                            ans.push_back(l + r);
                        }
                        else if (ch == '-') {
                            ans.push_back(l - r);
                        } 
                        else if (ch == '*') {
                            ans.push_back(l * r);
                        }

                    }
                }
            }
        }

        if(ans.empty()) {
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};