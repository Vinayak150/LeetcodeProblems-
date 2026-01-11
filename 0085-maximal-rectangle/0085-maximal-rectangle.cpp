class Solution {
public:
    int largestRectangleArea(const vector<int>& heights) {
        int n = heights.size();
        vector<int> st; // stack of indices, increasing heights
        int maxArea = 0;
        for (int i = 0; i <= n; ++i) {
            int h = (i == n ? 0 : heights[i]);
            while (!st.empty() && h < heights[st.back()]) {
                int height = heights[st.back()];
                st.pop_back();
                int left = st.empty() ? -1 : st.back();
                int width = i - left - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push_back(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == '1') heights[c] += 1;
                else heights[c] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};