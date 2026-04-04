class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (rows == 1) return encodedText;

        int cols = n / rows;
        vector<vector<char>> grid(rows, vector<char>(cols));

        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = encodedText[idx++];
            }
        }

        string res;

        for (int start = 0; start < cols; start++) {
            int i = 0, j = start;
            while (i < rows && j < cols) {
                res.push_back(grid[i][j]);
                i++;
                j++;
            }
        }

        while (!res.empty() && res.back() == ' ') res.pop_back();

        return res;
    }
};