class Solution {
public:
    int dp[1001][1001];

    int solve(string& s1, string& s2, int i, int j) {

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == s1.length()) {
            int sum = 0;
            for (int k = j; k < s2.length(); k++)
                sum += s2[k];
            return dp[i][j] = sum;
        }
        if (j == s2.length()) {
            int sum = 0;
            for (int k = i; k < s1.length(); k++)
                sum += s1[k];
            return dp[i][j] = sum;
        }

        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);
        }
        int deletefroms1 = s1[i] + solve(s1, s2, i + 1, j);
        int deletefroms2 = s2[j] + solve(s1, s2, i, j + 1);

        return dp[i][j] = min(deletefroms1, deletefroms2);
    }

    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0);
    }
};