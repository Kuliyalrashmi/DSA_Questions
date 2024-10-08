class Solution {
public:
    int minSwaps(string s) {
        int count = 0, maxImbalance = 0;
        for (char c : s) {
            if (c == '[') {
                count--;
            } else { // c == ']'
                count++;
            }
            maxImbalance = max(maxImbalance, count);
        }
        return (maxImbalance + 1) / 2;
    }
};
