
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dist[row][col][teleports_used]
        // Stores the minimum cost to reach (row, col) with 'used' teleports.
        // Initialize with infinity (2e9 is safe since max cost is roughly 80*80*10^4).
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(k + 1, 2e9)));
        
        // Priority Queue stores: {cost, row, col, k_used}
        // Min-heap: pops smallest cost first.
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
        
        // OPTIMIZATION:
        // Flatten all cells into a list and sort them by value.
        // This allows us to efficiently find valid teleport targets without scanning the whole grid.
        // Stores: {value, row, col}
        vector<tuple<int, int, int>> cellsByValue;
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                cellsByValue.push_back({grid[r][c], r, c});
            }
        }
        sort(cellsByValue.begin(), cellsByValue.end());
        
        // processedIndex[k] keeps track of how many cells in 'cellsByValue'
        // we have already teleported to using 'k' teleports.
        // Because Dijkstra processes costs in increasing order, once we teleport to a cell
        // in a specific 'k' layer, we never need to do it again for that layer.
        vector<int> processedIndex(k + 1, 0);
        
        // Initial state: Start at (0,0) with 0 cost and 0 teleports
        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});
        
        while (!pq.empty()) {
            auto [d, r, c, used] = pq.top();
            pq.pop();
            
            // If we found a shorter path to this state already, skip
            if (d > dist[r][c][used]) continue;
            
            // If we reached the bottom-right, return the cost immediately
            if (r == m - 1 && c == n - 1) return d;
            
            // --- 1. Normal Moves (Right and Down) ---
            int dr[] = {0, 1};
            int dc[] = {1, 0};
            
            for (int i = 0; i < 2; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newCost = d + grid[nr][nc];
                    if (newCost < dist[nr][nc][used]) {
                        dist[nr][nc][used] = newCost;
                        pq.push({newCost, nr, nc, used});
                    }
                }
            }
            
            // --- 2. Teleportation Moves ---
            // We can teleport if we have used less than 'k' jumps so far.
            if (used < k) {
                int nextK = used + 1;
                int currentVal = grid[r][c];
                
                // We use the sorted 'cellsByValue' list.
                // We start checking from where we left off for this 'nextK' layer.
                while (processedIndex[nextK] < cellsByValue.size()) {
                    auto [val, tr, tc] = cellsByValue[processedIndex[nextK]];
                    
                    // Condition: Can only teleport to cells with value <= currentVal
                    // Since the list is sorted, if we hit a value > currentVal, we stop immediately.
                    if (val > currentVal) break;
                    
                    // Teleport cost is 0. New cost remains 'd'.
                    if (d < dist[tr][tc][nextK]) {
                        dist[tr][tc][nextK] = d;
                        pq.push({d, tr, tc, nextK});
                    }
                    
                    // Move the pointer forward so we never check this cell again for this 'nextK' layer.
                    processedIndex[nextK]++;
                }
            }
        }
        
        return -1; // Should technically not reach here given constraints
    }
};