class Solution {
public:
    vector<string> ans;

    void dfs(int n, int op, int cl, string &s) {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        if (op < n) {
            s.push_back('(');
            dfs(n, op + 1, cl, s);
            s.pop_back();
        }

        if (cl < op) {
            s.push_back(')');
            dfs(n, op, cl + 1, s);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s;
        dfs(n, 0, 0, s);
        return ans;
    }
};