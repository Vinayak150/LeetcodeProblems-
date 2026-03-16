#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        
        vector<vector<long long>> dr(m, vector<long long>(n, 0));
        vector<vector<long long>> dl(m, vector<long long>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dr[i][j] = grid[i][j] + ((i > 0 && j > 0) ? dr[i-1][j-1] : 0LL);
                dl[i][j] = grid[i][j] + ((i > 0 && j + 1 < n) ? dl[i-1][j+1] : 0LL);
            }
        }

       
        auto sum_dr = [&](int r1, int c1, int r2, int c2) -> long long {
            if (r1 > r2 || c1 > c2) return 0LL;
            long long res = dr[r2][c2];
            if (r1 - 1 >= 0 && c1 - 1 >= 0) res -= dr[r1-1][c1-1];
            return res;
        };
        
        auto sum_dl = [&](int r1, int c1, int r2, int c2) -> long long {
            if (r1 > r2 || c1 < c2) return 0LL;
            long long res = dl[r2][c2];
            if (r1 - 1 >= 0 && c1 + 1 < n) res -= dl[r1-1][c1+1];
            return res;
        };

        set<long long> uniq;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
               
                uniq.insert(grid[i][j]);

                for (int k = 1; ; ++k) {
                    if (i + 2*k >= m || j - k < 0 || j + k >= n) break;

                    

                    long long s_top_right = sum_dr(i, j, i + k, j + k);           
                    long long s_right_bottom = sum_dl(i + k, j + k, i + 2*k, j);   
                    long long s_left_bottom = sum_dr(i + k, j - k, i + 2*k, j);    // left -> bottom (left -> bottom is down-right)
                    long long s_top_left = sum_dl(i, j, i + k, j - k);             // top -> left (down-left)

                    
                    long long total = s_top_right + s_right_bottom + s_left_bottom + s_top_left
                                      - grid[i][j] - grid[i+k][j+k] - grid[i+2*k][j] - grid[i+k][j-k];

                    uniq.insert(total);
                }
            }
        }

        vector<int> ans;
        for (auto it = uniq.rbegin(); it != uniq.rend() && ans.size() < 3; ++it) ans.push_back((int)*it);
        return ans;
    }
};