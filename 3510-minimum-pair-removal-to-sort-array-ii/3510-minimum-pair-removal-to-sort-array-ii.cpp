class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<long long> vals(nums.begin(), nums.end());
        vector<int> left(n), right(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        right[n - 1] = -1;

        // count initial adjacent inversions
        int inv = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (vals[i] > vals[i + 1]) inv++;
        }
        if (inv == 0) return 0;

        // min-heap of (pair_sum, left_index)
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        for (int i = 0; i + 1 < n; i++) {
            pq.push({vals[i] + vals[i + 1], i});
        }

        int ops = 0;

        while (!pq.empty()) {
            auto [s, i] = pq.top();
            pq.pop();

            if (i < 0 || i >= n || !alive[i]) continue;
            int j = right[i];
            if (j == -1 || !alive[j]) continue;

            // CRUCIAL lazy check: value consistency
            if (vals[i] + vals[j] != s) continue;

            int li = left[i];
            int rj = right[j];

            // remove old inversion contributions
            if (li != -1 && alive[li] && vals[li] > vals[i]) inv--;
            if (vals[i] > vals[j]) inv--;
            if (rj != -1 && alive[rj] && vals[j] > vals[rj]) inv--;

            // merge j into i
            vals[i] = s;
            alive[j] = false;
            right[i] = rj;
            if (rj != -1) left[rj] = i;

            // add new inversion contributions
            if (li != -1 && alive[li] && vals[li] > vals[i]) inv++;
            if (right[i] != -1 && alive[right[i]] && vals[i] > vals[right[i]]) inv++;

            ops++;
            if (inv == 0) return ops;

            // push updated adjacent pairs
            if (li != -1 && alive[li]) {
                pq.push({vals[li] + vals[i], li});
            }
            if (right[i] != -1 && alive[right[i]]) {
                pq.push({vals[i] + vals[right[i]], i});
            }
        }

        return ops;
    }
};