class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long max_side = 0;
        int n = bottomLeft.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long bl_x = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long bl_y = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long tr_x = min(topRight[i][0], topRight[j][0]);
                long long tr_y = min(topRight[i][1], topRight[j][1]);
                
                if (bl_x < tr_x && bl_y < tr_y) {
                    long long side = min(tr_x - bl_x, tr_y - bl_y);
                    max_side = max(max_side, side);
                }
            }
        }
        
        return max_side * max_side;
    }
};