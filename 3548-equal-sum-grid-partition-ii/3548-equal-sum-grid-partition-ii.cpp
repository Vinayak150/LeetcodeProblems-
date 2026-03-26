#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MAXV = 100000;

        vector<long long> rowSum(m, 0), colSum(n, 0);
        vector<vector<int>> rowsByVal(MAXV + 1);
        vector<vector<int>> colsByVal(MAXV + 1);

        long long total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                total += val;
                rowSum[i] += val;
                colSum[j] += val;
                rowsByVal[val].push_back(i);
                colsByVal[val].push_back(j);
            }
        }

        auto existsInRange = [&](const vector<int>& vec, int L, int R) -> bool {
            auto it = lower_bound(vec.begin(), vec.end(), L);
            return it != vec.end() && *it <= R;
        };

        for (int v = 1; v <= MAXV; v++) {
            if (!rowsByVal[v].empty()) sort(rowsByVal[v].begin(), rowsByVal[v].end());
            if (!colsByVal[v].empty()) sort(colsByVal[v].begin(), colsByVal[v].end());
        }

        auto canDiscountHorizontal = [&](int top, int bottom, long long diff) -> bool {
            int height = bottom - top + 1;

            if (diff <= 0 || diff > MAXV) return false;

            if (height == 1) {
                if (n == 1) return false;
                return grid[top][0] == diff || grid[top][n - 1] == diff;
            }

            if (n == 1) {
                return grid[top][0] == diff || grid[bottom][0] == diff;
            }

            const vector<int>& rows = rowsByVal[(int)diff];
            return existsInRange(rows, top, bottom);
        };

        auto canDiscountVertical = [&](int left, int right, long long diff) -> bool {
            int width = right - left + 1;

            if (diff <= 0 || diff > MAXV) return false;

            if (width == 1) {
                if (m == 1) return false;
                return grid[0][left] == diff || grid[m - 1][left] == diff;
            }

            if (m == 1) {
                return grid[0][left] == diff || grid[0][right] == diff;
            }

            const vector<int>& cols = colsByVal[(int)diff];
            return existsInRange(cols, left, right);
        };

        long long topSum = 0;
        for (int r = 0; r < m - 1; r++) {
            topSum += rowSum[r];
            long long bottomSum = total - topSum;

            if (topSum == bottomSum) return true;

            if (topSum > bottomSum) {
                long long diff = topSum - bottomSum;
                if (canDiscountHorizontal(0, r, diff)) return true;
            } else {
                long long diff = bottomSum - topSum;
                if (canDiscountHorizontal(r + 1, m - 1, diff)) return true;
            }
        }

        long long leftSum = 0;
        for (int c = 0; c < n - 1; c++) {
            leftSum += colSum[c];
            long long rightSum = total - leftSum;

            if (leftSum == rightSum) return true;

            if (leftSum > rightSum) {
                long long diff = leftSum - rightSum;
                if (canDiscountVertical(0, c, diff)) return true;
            } else {
                long long diff = rightSum - leftSum;
                if (canDiscountVertical(c + 1, n - 1, diff)) return true;
            }
        }

        return false;
    }
};