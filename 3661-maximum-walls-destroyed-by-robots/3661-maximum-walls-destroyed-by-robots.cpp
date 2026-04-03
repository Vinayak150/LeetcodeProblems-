#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; ++i) a[i] = {robots[i], distance[i]};
        sort(a.begin(), a.end());

        vector<int> p(n), d(n);
        unordered_set<int> rs;
        rs.reserve(n * 2);

        for (int i = 0; i < n; ++i) {
            p[i] = a[i].first;
            d[i] = a[i].second;
            rs.insert(p[i]);
        }

        sort(walls.begin(), walls.end());

        auto cnt = [&](int L, int R) -> int {
            if (L > R) return 0;
            return (int)(upper_bound(walls.begin(), walls.end(), R) -
                         lower_bound(walls.begin(), walls.end(), L));
        };

        int base = 0;
        for (int w : walls) if (rs.count(w)) ++base;

        if (n == 1) {
            int left = cnt(p[0] - d[0], p[0] - 1);
            int right = cnt(p[0] + 1, p[0] + d[0]);
            return base + max(left, right);
        }

        int dpL = cnt(p[0] - d[0], p[0] - 1);
        int dpR = 0;

        for (int i = 0; i < n - 1; ++i) {
            int A = cnt(p[i] + 1, min(p[i] + d[i], p[i + 1] - 1));
            int B = cnt(max(p[i + 1] - d[i + 1], p[i] + 1), p[i + 1] - 1);
            int O = cnt(max(p[i] + 1, p[i + 1] - d[i + 1]), min(p[i] + d[i], p[i + 1] - 1));

            int ndpL = max(dpL + B, dpR + A + B - O);
            int ndpR = max(dpL, dpR + A);

            dpL = ndpL;
            dpR = ndpR;
        }

        int rightEdge = cnt(p[n - 1] + 1, p[n - 1] + d[n - 1]);
        return base + max(dpL, dpR + rightEdge);
    }
};