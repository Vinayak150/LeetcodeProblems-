class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> st;
        for (auto &o : obstacles) {
            long long key = ((long long)o[0] << 32) | (unsigned int)o[1];
            st.insert(key);
        }

        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int d = 0, x = 0, y = 0, ans = 0;

        for (int c : commands) {
            if (c == -2) {
                d = (d + 3) % 4;
            } else if (c == -1) {
                d = (d + 1) % 4;
            } else {
                for (int i = 0; i < c; i++) {
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;
                    long long key = ((long long)nx << 32) | (unsigned int)ny;
                    if (st.count(key)) break;
                    x = nx;
                    y = ny;
                    ans = max(ans, x*x + y*y);
                }
            }
        }

        return ans;
    }
};