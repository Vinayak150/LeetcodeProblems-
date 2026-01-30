class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        int n = source.size();
        const long long INF = 1e18;

        // dp[i] = min cost to convert prefix [0..i-1]
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        // group rules by length
        unordered_map<int, vector<int>> rulesByLen;
        for (int i = 0; i < original.size(); i++) {
            rulesByLen[original[i].size()].push_back(i);
        }

        // For each length, build shortest-path map
        unordered_map<int, unordered_map<string, unordered_map<string, long long>>> best;

        for (auto& [L, ids] : rulesByLen) {
            // collect all strings of this length
            unordered_set<string> nodes;
            for (int id : ids) {
                nodes.insert(original[id]);
                nodes.insert(changed[id]);
            }

            // build distance map
            unordered_map<string, unordered_map<string, long long>> dist;
            for (auto& s : nodes)
                for (auto& t : nodes)
                    dist[s][t] = (s == t ? 0 : INF);

            for (int id : ids) {
                dist[original[id]][changed[id]] =
                    min(dist[original[id]][changed[id]], (long long)cost[id]);
            }

            // Floyd–Warshall
            for (auto& k : nodes)
                for (auto& i : nodes)
                    for (auto& j : nodes)
                        if (dist[i][k] < INF && dist[k][j] < INF)
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

            best[L] = dist;
        }

        // DP
        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            // single character match
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // substring conversions
            for (auto& [L, table] : best) {
                if (i + L > n) continue;

                string s1 = source.substr(i, L);
                string s2 = target.substr(i, L);

                if (table.count(s1) && table[s1].count(s2) &&
                    table[s1][s2] < INF) {
                    dp[i + L] = min(dp[i + L], dp[i] + table[s1][s2]);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
