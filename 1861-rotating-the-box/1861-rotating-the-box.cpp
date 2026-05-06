class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // STEP 1: Simulate gravity (RIGHT direction)
        for (int i = 0; i < m; i++) {

            int emptyPos = n - 1; // where next stone should go

            for (int j = n - 1; j >= 0; j--) {

                // Case 1: obstacle
                if (boxGrid[i][j] == '*') {
                    emptyPos = j - 1; // reset position
                }

                // Case 2: stone
                else if (boxGrid[i][j] == '#') {

                    // move stone to emptyPos
                    char temp = boxGrid[i][emptyPos];
                    boxGrid[i][emptyPos] = '#';
                    boxGrid[i][j] = temp;

                    emptyPos--; // next available spot
                }

                // Case 3: empty → do nothing
            }
        }

        // STEP 2: Rotate 90 degree clockwise
        vector<vector<char>> result(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // rotation formula
                result[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return result;
    }
};