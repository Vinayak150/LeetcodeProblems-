class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        vector<int> ans(n, 1);

        auto dfs = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prev = last[c];
            last[c] = u;

            for (int v : adj[u]) {
                self(self, v);
            }

            last[c] = prev;

            if (u != 0) {
                int target = (prev != -1) ? prev : parent[u];
                ans[target] += ans[u];
            }
        };

        dfs(dfs, 0);
        return ans;
    }
};