#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {0, 0};

        // compute mismatches for both patterns
        // pattern0: even index -> even(0), odd index -> odd(1) => expected = i%2
        // pattern1: expected = 1 - i%2
        int mism0 = 0, mism1 = 0;
        for (int i = 0; i < n; ++i) {
            int p = (nums[i] & 1) ? 1 : 0;
            if (p != (i % 2)) ++mism0;
            if (p != (1 - (i % 2))) ++mism1;
        }
        int minOps = min(mism0, mism1);

        // helper to compute minimal range for a given pattern only if its ops == minOps
        auto compute_min_range_for_pattern = [&](int pattern_expected_if_even_index)->long long {
            int opsNeeded = 0;
            // gather candidate values
            vector<long long> allVals;
            allVals.reserve(n * 2);
            vector<array<long long,2>> choices(n); // store up to 2 choices; if only one, both equal
            vector<char> hasTwo(n, 0);

            for (int i = 0; i < n; ++i) {
                int expected = ( (i % 2) == 0 ) ? pattern_expected_if_even_index : 1 - pattern_expected_if_even_index;
                int curParity = (nums[i] & 1) ? 1 : 0;
                if (curParity == expected) {
                    // matched: only nums[i]
                    choices[i][0] = choices[i][1] = nums[i];
                    allVals.push_back(nums[i]);
                } else {
                    // mismatched: must do exactly one operation => either -1 or +1
                    ++opsNeeded;
                    long long v1 = (long long)nums[i] - 1;
                    long long v2 = (long long)nums[i] + 1;
                    choices[i][0] = v1;
                    choices[i][1] = v2;
                    hasTwo[i] = 1;
                    allVals.push_back(v1);
                    allVals.push_back(v2);
                }
            }

            if (opsNeeded != minOps) return LLONG_MAX; // this pattern doesn't match minimal ops

            // unique sort
            sort(allVals.begin(), allVals.end());
            allVals.erase(unique(allVals.begin(), allVals.end()), allVals.end());
            int m = (int)allVals.size();
            // holders: for each unique value, which indices can take that value
            vector<vector<int>> holders(m);
            for (int i = 0; i < n; ++i) {
                // first choice
                long long v = choices[i][0];
                int idx = int(lower_bound(allVals.begin(), allVals.end(), v) - allVals.begin());
                holders[idx].push_back(i);
                // second choice if different
                if (hasTwo[i]) {
                    v = choices[i][1];
                    idx = int(lower_bound(allVals.begin(), allVals.end(), v) - allVals.begin());
                    holders[idx].push_back(i);
                }
            }

            // sliding window to cover all indices
            vector<int> freq(n, 0);
            int covered = 0;
            int r = 0;
            long long bestRange = LLONG_MAX;
            for (int l = 0; l < m; ++l) {
                while (r < m && covered < n) {
                    for (int idx : holders[r]) {
                        if (freq[idx] == 0) ++covered;
                        ++freq[idx];
                    }
                    ++r;
                }
                if (covered == n) {
                    long long curRange = allVals[r-1] - allVals[l];
                    if (curRange < bestRange) bestRange = curRange;
                } else {
                    // cannot cover all further (r == m and covered < n)
                    break;
                }
                // remove l
                for (int idx : holders[l]) {
                    --freq[idx];
                    if (freq[idx] == 0) --covered;
                }
            }
            return bestRange;
        };

        long long range0 = compute_min_range_for_pattern(0); // even index -> even
        long long range1 = compute_min_range_for_pattern(1); // even index -> odd

        long long bestRange = min(range0, range1);
        if (bestRange == LLONG_MAX) bestRange = 0; // defensive, though shouldn't happen

        return {minOps, (int)bestRange};
    }
};