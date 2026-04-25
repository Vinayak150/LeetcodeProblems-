class Solution {
public:
    long long getPos(int x, int y, int side) {
        if (y == 0) return x;
        if (x == side) return side + y;
        if (y == side) return 2LL * side + (side - x);
        return 3LL * side + (side - y);
    }

    bool can(long long d, const vector<long long>& pos, int k, long long per) {
        int n = pos.size();
        int m = 2 * n;
        vector<long long> ext(m);

        for (int i = 0; i < n; i++) {
            ext[i] = pos[i];
            ext[i + n] = pos[i] + per;
        }

        int LOG = 0;
        while ((1 << LOG) <= k) LOG++;

        vector<vector<int>> up(LOG, vector<int>(m + 1, m));

        int right = 0;
        for (int left = 0; left < m; left++) {
            while (right < m && ext[right] - ext[left] < d) {
                right++;
            }
            up[0][left] = right;
        }
        up[0][m] = m;

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i <= m; i++) {
                if (up[j - 1][i] == m) {
                    up[j][i] = m;
                } else {
                    up[j][i] = up[j - 1][up[j - 1][i]];
                }
            }
        }

        int jumps = k - 1;
        for (int i = 0; i < n; i++) {
            int curr = i;

            for (int j = 0; j < LOG; j++) {
                if ((jumps >> j) & 1) {
                    curr = up[j][curr];
                    if (curr == m) break;
                }
            }

            if (curr < m && ext[curr] - ext[i] <= per - d) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;

        for (const auto &p : points) {
            pos.push_back(getPos(p[0], p[1], side));
        }

        sort(pos.begin(), pos.end());

        long long low = 0, high = 4LL * side, ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (can(mid, pos, k, 4LL * side)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};