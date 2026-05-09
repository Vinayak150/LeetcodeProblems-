class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            int top = layer;
            int bottom = m - 1 - layer;
            int left = layer;
            int right = n - 1 - layer;

            vector<int> ring;

            // 1) top row: left -> right
            for (int j = left; j <= right; j++) {
                ring.push_back(grid[top][j]);
            }

            // 2) right column: top+1 -> bottom-1
            for (int i = top + 1; i <= bottom - 1; i++) {
                ring.push_back(grid[i][right]);
            }

            // 3) bottom row: right -> left
            for (int j = right; j >= left; j--) {
                ring.push_back(grid[bottom][j]);
            }

            // 4) left column: bottom-1 -> top+1
            for (int i = bottom - 1; i >= top + 1; i--) {
                ring.push_back(grid[i][left]);
            }

            int len = ring.size();
            int shift = k % len;

            // Rotate counter-clockwise => left shift in this ordering
            vector<int> rotated(len);
            for (int i = 0; i < len; i++) {
                rotated[i] = ring[(i + shift) % len];
            }

            int idx = 0;

            // Put values back in the same traversal order
            for (int j = left; j <= right; j++) {
                grid[top][j] = rotated[idx++];
            }

            for (int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = rotated[idx++];
            }

            for (int j = right; j >= left; j--) {
                grid[bottom][j] = rotated[idx++];
            }

            for (int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = rotated[idx++];
            }
        }

        return grid;
    }
};