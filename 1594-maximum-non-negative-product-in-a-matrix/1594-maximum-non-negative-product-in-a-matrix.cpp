class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        
        vector<vector<long long>> dpMax(m, vector<long long>(n));
        vector<vector<long long>> dpMin(m, vector<long long>(n));

  
        dpMax[0][0] = grid[0][0];
        dpMin[0][0] = grid[0][0];

        
        for (int j = 1; j < n; j++) {
            dpMax[0][j] = dpMax[0][j-1] * grid[0][j];
            dpMin[0][j] = dpMax[0][j];
        }

        
        for (int i = 1; i < m; i++) {
            dpMax[i][0] = dpMax[i-1][0] * grid[i][0];
            dpMin[i][0] = dpMax[i][0];
        }

        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                long long val = grid[i][j];

                
                long long topMax = dpMax[i-1][j];
                long long topMin = dpMin[i-1][j];

                
                long long leftMax = dpMax[i][j-1];
                long long leftMin = dpMin[i][j-1];

                
                long long a = topMax * val;
                long long b = topMin * val;
                long long c = leftMax * val;
                long long d = leftMin * val;

                
                dpMax[i][j] = max({a, b, c, d});
                dpMin[i][j] = min({a, b, c, d});
            }
        }

        long long result = dpMax[m-1][n-1];

        
        if (result < 0) return -1;

        return result % 1000000007;
    }
};