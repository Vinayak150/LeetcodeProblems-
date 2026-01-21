class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());
        for (int t : nums) {
            long long best = -1;
            // r = position of lowest set bit in y (0-based)
            for (int r = 0; r <= 31; ++r) {
                long long mask = (r == 0) ? 0LL : ((1LL << r) - 1);
                // lower r bits of t must be all ones
                if ((t & mask) != mask) continue;
                // form y by clearing lower r bits of t
                long long y = (long long)t & ~mask;
                // y must have bit r == 1 (so its LSB is at r)
                if (((y >> r) & 1LL) == 0) continue;
                long long x = y - 1;
                if ((x | (x + 1)) == t) {
                    if (best == -1 || x < best) best = x;
                }
            }
            ans.push_back((best == -1) ? -1 : (int)best);
        }
        return ans;
    }
};