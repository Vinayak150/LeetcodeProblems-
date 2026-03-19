#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

       
        vector<vector<int>> prefixX(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> prefixY(m + 1, vector<int>(n + 1, 0));

        int ans = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                int addX = (grid[i - 1][j - 1] == 'X') ? 1 : 0;

               
                int addY = (grid[i - 1][j - 1] == 'Y') ? 1 : 0;

           
                prefixX[i][j] = prefixX[i - 1][j] + prefixX[i][j - 1]
                              - prefixX[i - 1][j - 1] + addX;

                
                prefixY[i][j] = prefixY[i - 1][j] + prefixY[i][j - 1]
                              - prefixY[i - 1][j - 1] + addY;

                
                if (prefixX[i][j] == prefixY[i][j] && prefixX[i][j] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};