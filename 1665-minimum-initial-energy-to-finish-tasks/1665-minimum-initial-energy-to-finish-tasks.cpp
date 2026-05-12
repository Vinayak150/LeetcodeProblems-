class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        long long energy = 0;

        for (int i = (int)tasks.size() - 1; i >= 0; i--) {
            energy = max(energy + tasks[i][0], (long long)tasks[i][1]);
        }

        return (int)energy;
    }
};