class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {

        if (k == 1) return nums[0];

        multiset<int> small, large;
        long long sumSmall = 0;
        long long ans = LLONG_MAX;

        // Initial window [1 ... dist+1]
        for (int i = 1; i <= dist + 1; i++) {
            small.insert(nums[i]);
            sumSmall += nums[i];
        }

        // Keep only k-1 smallest
        while (small.size() > k - 1) {
            auto it = prev(small.end());
            sumSmall -= *it;
            large.insert(*it);
            small.erase(it);
        }

        ans = sumSmall;

        // Sliding window
        for (int i = dist + 2; i < nums.size(); i++) {

            int out = nums[i - (dist + 1)];
            int in = nums[i];

            // Remove outgoing (FAST version)
            auto it = small.find(out);
            if (it != small.end()) {
                sumSmall -= out;
                small.erase(it);
            } else {
                large.erase(large.find(out));
            }

            // Insert incoming
            if (!small.empty() && in <= *prev(small.end())) {
                small.insert(in);
                sumSmall += in;
            } else {
                large.insert(in);
            }

            // Rebalance
            while (small.size() < k - 1) {
                auto it2 = large.begin();
                sumSmall += *it2;
                small.insert(*it2);
                large.erase(it2);
            }

            while (small.size() > k - 1) {
                auto it2 = prev(small.end());
                sumSmall -= *it2;
                large.insert(*it2);
                small.erase(it2);
            }

            ans = min(ans, sumSmall);
        }

        return ans + nums[0];
    }
};
