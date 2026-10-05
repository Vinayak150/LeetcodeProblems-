class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, dep = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                dep++;
            } else {
                dep--;

                if (s[i - 1] == '(') {
                    ans += (1 << dep);
                }
            }
        }

        return ans;
    }
};