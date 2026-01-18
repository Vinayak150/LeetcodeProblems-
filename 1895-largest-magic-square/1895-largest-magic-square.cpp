class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 1;
        for(int i =0;i<m;i++){
            for(int j =0; j<n;j++){
                for(int k =2;i + k <= m && j + k <= n; k++){
                    if(isMagic(grid,i,j,k)){
                        ans = max(ans,k);
                    }
                }
            }
        }
        
        return ans;
    }

    bool isMagic(vector<vector<int>>& grid,int r,int c, int k){
        int target =0;
        for(int j =c;j<c + k;j++){
            target +=grid[r][j];
        }
        for(int i =r;i < r + k;i++){
            int sum =0;
            for(int j =c;j<c+k;j++){
                sum +=grid[i][j];
            }
            if(sum!=target) return false;
        }
        for(int j = c;j <c + k; j++){
            int sum = 0;
            for(int i =r; i < r +k;i++){
                sum += grid[i][j];
            }
            if(sum !=target) return false;
        }
        int diag1 =0;
        for(int i =0; i<k;i++){
            diag1 +=grid[r+i][c+i];
        }
        int diag2 =0;
        for(int i =0; i<k;i++){
            diag2 += grid[r+i][c+k-1-i];
        }
        return diag1 == target && diag2 == target;
    }
};