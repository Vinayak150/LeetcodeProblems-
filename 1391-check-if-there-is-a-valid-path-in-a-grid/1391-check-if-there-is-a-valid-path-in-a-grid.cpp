class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        vector<vector<int>> dirs = {
            {},
            {2, 3},
            {0, 1},
            {2, 1},
            {3, 1},
            {2, 0},
            {3, 0}
        };
        
        vector<int> opposite = {1, 0, 3, 2};
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        vis[0][0] = true;
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            if (x == m - 1 && y == n - 1) {
                return true;
            }
            
            int type = grid[x][y];
            
            for (int d : dirs[type]) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                    continue;
                }
                
                if (vis[nx][ny]) {
                    continue;
                }
                
                int nextType = grid[nx][ny];
                
                bool ok = false;
                for (int nd : dirs[nextType]) {
                    if (nd == opposite[d]) {
                        ok = true;
                        break;
                    }
                }
                
                if (ok) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        
        return false;
    }
};