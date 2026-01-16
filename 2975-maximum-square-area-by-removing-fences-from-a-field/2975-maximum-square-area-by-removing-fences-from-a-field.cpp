class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1'000'000'007LL;
        // include boundaries and sort
        hFences.push_back(1); hFences.push_back(m);
        vFences.push_back(1); vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // compute all differences between any two positions for horizontals, store in unordered_set
        unordered_set<int> hLens;
        int H = hFences.size();
        for (int i = 0; i < H; ++i) {
            for (int j = i + 1; j < H; ++j) {
                hLens.insert(hFences[j] - hFences[i]);
            }
        }

        // compute vertical differences and track max common length
        int best = -1;
        int V = vFences.size();
        for (int i = 0; i < V; ++i) {
            for (int j = i + 1; j < V; ++j) {
                int len = vFences[j] - vFences[i];
                if (hLens.find(len) != hLens.end()) best = max(best, len);
            }
        }

        if (best == -1) return -1;
        return (int)((1LL * best * best) % MOD);
    }
};