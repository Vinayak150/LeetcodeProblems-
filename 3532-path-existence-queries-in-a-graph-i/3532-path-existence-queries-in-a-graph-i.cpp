class Solution {
public:
    vector<int> parent, rank;

    // Find representative with path compression
    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    // Union by rank
    void unite(int x, int y) {

        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    vector<bool> pathExistenceQueries(int n,
                                      vector<int>& nums,
                                      int maxDiff,
                                      vector<vector<int>>& queries) {

        parent.resize(n);
        rank.assign(n, 0);

        // Initially every node is its own parent
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Union only adjacent nodes
        for (int i = 1; i < n; i++) {

            if (nums[i] - nums[i - 1] <= maxDiff)
                unite(i, i - 1);
        }

        vector<bool> answer;

        // Answer each query
        for (auto &q : queries) {

            int u = q[0];
            int v = q[1];

            answer.push_back(find(u) == find(v));
        }

        return answer;
    }
};