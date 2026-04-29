class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<vector<long long>> pref(n, vector<long long>(n + 1, 0));
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                pref[col][row + 1] = pref[col][row] + grid[row][col];
            }
        }
        const long long NEG = -(1LL << 60);
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, NEG));
        for (int b = 0; b <= n; b++) {
            dp[0][b] = 0;
        }
        for (int col = 0; col < n; col++) {
            vector<vector<long long>> ndp(n + 1, vector<long long>(n + 1, NEG));
            const vector<long long>& ps = pref[col];
            for (int b = 0; b <= n; b++) {
                vector<long long> leftBest(n + 1, NEG);
                leftBest[0] = dp[0][b];
                for (int a = 1; a <= n; a++) {
                    leftBest[a] = max(leftBest[a - 1], dp[a][b]);
                }
                vector<long long> rightBest(n + 1, NEG);
                rightBest[n] = (dp[n][b] == NEG ? NEG : dp[n][b] + ps[n]);
                for (int a = n - 1; a >= 0; a--) {
                    long long cur = (dp[a][b] == NEG ? NEG : dp[a][b] + ps[a]);
                    rightBest[a] = max(rightBest[a + 1], cur);
                }
                for (int c = 0; c <= n; c++) {
                    if (col == n - 1 && c != 0) continue;
                    long long best = NEG;
                    if (c <= b) {
                        best = max(best, leftBest[b]);
                        if (b + 1 <= n && rightBest[b + 1] != NEG) {
                            best = max(best, rightBest[b + 1] - ps[b]);
                        }
                    } else {
                        if (leftBest[c] != NEG) {
                            best = max(best, leftBest[c] + ps[c] - ps[b]);
                        }
                        if (c + 1 <= n && rightBest[c + 1] != NEG) {
                            best = max(best, rightBest[c + 1] - ps[b]);
                        }
                    }
                    ndp[b][c] = max(ndp[b][c], best);
                }
            }
            dp.swap(ndp);
        }
        long long ans = 0;
        for (int a = 0; a <= n; a++) {
            ans = max(ans, dp[a][0]);
        }
        return ans;
    }
};