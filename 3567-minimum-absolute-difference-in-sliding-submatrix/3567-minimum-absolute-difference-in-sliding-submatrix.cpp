class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        
        for(int i = 0; i <= m - k; ++i) {
            for(int j = 0; j <= n - k; ++j) {
                vector<int> nums;
                nums.reserve(k * k);
                
                
                for(int x = i; x < i + k; ++x) {
                    for(int y = j; y < j + k; ++y) {
                        nums.push_back(grid[x][y]);
                    }
                }
                
                sort(nums.begin(), nums.end());
                int min_diff = INT_MAX;
                
                
                for(size_t t = 1; t < nums.size(); ++t) {
                    if(nums[t] != nums[t-1]) {
                        min_diff = min(min_diff, nums[t] - nums[t-1]);
                    }
                }
                
                if(min_diff == INT_MAX) {
                    ans[i][j] = 0;
                } else {
                    ans[i][j] = min_diff;
                }
            }
        }
        return ans;
    }
};