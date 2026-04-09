class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size(), ans = 0;
        
        auto canCross = [&](int day) {
            vector<vector<int>> grid(row, vector<int>(col, 0));
            for (int i = 0; i < day; ++i) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }
            
            queue<pair<int, int>> q;
            for (int j = 0; j < col; ++j) {
                if (grid[0][j] == 0) {
                    q.push({0, j});
                    grid[0][j] = -1;
                }
            }
            
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                
                if (r == row - 1) return true;
                
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    
                    if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0) {
                        grid[nr][nc] = -1;
                        q.push({nr, nc});
                    }
                }
            }
            return false;
        };
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canCross(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};