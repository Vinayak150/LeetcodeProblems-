class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int size = n * m;

        
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr.push_back(grid[i][j]);
            }
        }

       
        vector<long long> prefix(size, 1);

        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i-1] * arr[i-1]) % 12345;
        }

        
        vector<long long> suffix(size, 1);

        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i+1] * arr[i+1]) % 12345;
        }

        
        vector<int> result(size);

        for (int i = 0; i < size; i++) {
            result[i] = (prefix[i] * suffix[i]) % 12345;
        }

        
        vector<vector<int>> ans(n, vector<int>(m));

        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = result[idx++];
            }
        }

        return ans;
    }
};