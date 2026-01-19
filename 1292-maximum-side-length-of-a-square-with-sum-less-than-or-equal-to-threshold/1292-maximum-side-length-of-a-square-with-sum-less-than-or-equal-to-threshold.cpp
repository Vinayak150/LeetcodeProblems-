class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                for (int k = 1; i + k <= m && j + k <= n; k++) {

                    for (int c = j; c < j + k; c++) {
                        sum += mat[i + k - 1][c];
                    }
                    for (int r = i; r < i + k - 1; r++) {
                        sum += mat[r][j + k - 1];
                    }

                    if (sum > threshold)
                        break;
                    ans = max(ans, k);
                }
            }
        }
        return ans;
    }
};