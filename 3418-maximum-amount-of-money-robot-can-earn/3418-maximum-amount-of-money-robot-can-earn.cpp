class Solution {
public:
    int maximumAmount(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

       
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));

       
        for (int k = 0; k <= 2; k++) {
            if (grid[0][0] >= 0) {
                dp[0][0][k] = grid[0][0];
            } else {
                
                dp[0][0][k] = grid[0][0];
                if (k > 0) dp[0][0][k] = 0;
            }
        }

      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k <= 2; k++) {

                    int best = INT_MIN;

                    
                    if (i > 0) best = max(best, dp[i-1][j][k]);

              
                    if (j > 0) best = max(best, dp[i][j-1][k]);

                    if (best == INT_MIN) continue;

                   
                    dp[i][j][k] = best + grid[i][j];

                   
                    if (grid[i][j] < 0 && k > 0) {
                        int bestPrev = INT_MIN;

                        if (i > 0) bestPrev = max(bestPrev, dp[i-1][j][k-1]);
                        if (j > 0) bestPrev = max(bestPrev, dp[i][j-1][k-1]);

                        if (bestPrev != INT_MIN) {
                            dp[i][j][k] = max(dp[i][j][k], bestPrev);
                        }
                    }
                }
            }
        }

       
        return max({dp[n-1][m-1][0], dp[n-1][m-1][1], dp[n-1][m-1][2]});
    }
};