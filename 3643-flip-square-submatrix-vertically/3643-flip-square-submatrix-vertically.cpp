class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i =0; i<k/2;i++){
            for(int j=0;j<k;j++){
                int r1 =x+i;
                int c1=y+j;
                int r2 =x+(k-1-i);
                int c2 =y+j;
                swap(grid[r1][c1],grid[r2][c2]);
            }
        }
        return grid;
        
    }
};