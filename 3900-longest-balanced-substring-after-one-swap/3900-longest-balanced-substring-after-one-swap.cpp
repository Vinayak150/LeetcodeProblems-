class Solution {
public:
    int longestBalanced(string s) {
        int n = (int)s.size();
        vector<int> pref(n + 1, 0);
        int zeros = 0;

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (s[i] == '1' ? 1 : -1);
            zeros += (s[i] == '0');
        }

        int ones = n - zeros;
        vector<vector<int>> pos(2 * n + 1);
        for (int i = 0; i <= n; i++) pos[pref[i] + n].push_back(i);

        auto solve = [&](int target, int lim) {
            vector<int> ptr(2 * n + 1, 0);
            int best = 0;

            for (int j = 0; j <= n; j++) {
                int need = pref[j] - target + n;
                if (need < 0 || need > 2 * n) continue;

                auto &v = pos[need];
                int &p = ptr[need];

                while (p < (int)v.size() && v[p] < j - lim) p++;
                if (p < (int)v.size() && v[p] < j) best = max(best, j - v[p]);
            }

            return best;
        };

        return max({solve(0, n), solve(2, 2 * zeros), solve(-2, 2 * ones)});
    }
};