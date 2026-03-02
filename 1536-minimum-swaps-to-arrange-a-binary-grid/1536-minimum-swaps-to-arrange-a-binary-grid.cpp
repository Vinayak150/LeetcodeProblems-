class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n =grid.size();
        vector<int> last(n,-1);
        for(int r =0; r<n; r++){
            for(int c = n-1;c>=0;c--){
                if(grid[r][c]==1){
                    last[r]=c;
                    break;
                }
            }
        }
        int s =0;
        for(int i =0; i<n;i++){
            int j =i;
            while( j<n && last[j]>i){
                j++;
            }
            if(j==n){
                return -1;
            }
            while(j>i){
                swap(last[j],last[j-1]);
                s++;
                j--;
            }
        }
        return s;
    }
};