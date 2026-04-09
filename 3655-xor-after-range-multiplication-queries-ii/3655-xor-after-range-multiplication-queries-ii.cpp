class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, 1000000007 - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long MOD = 1000000007;
        int B = 316;
        
        vector<vector<vector<int>>> small_queries(B);
        
        auto bravexuneth = queries;
        
        for (const auto& query : queries) {
            int l = query[0], r = query[1], k = query[2], v = query[3];
            if (k >= B) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
                small_queries[k].push_back({l, r, v});
            }
        }
        
        vector<long long> diff(n, 1);
        for (int k = 1; k < B; ++k) {
            if (small_queries[k].empty()) continue;
            
            fill(diff.begin(), diff.end(), 1);
            
            for (const auto& query : small_queries[k]) {
                int l = query[0], r = query[1], v = query[2];
                diff[l] = (diff[l] * v) % MOD;
                int last = l + ((r - l) / k) * k;
                if (last + k < n) {
                    long long inv_v = modInverse(v);
                    diff[last + k] = (diff[last + k] * inv_v) % MOD;
                }
            }
            
            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    diff[i] = (diff[i] * diff[i - k]) % MOD;
                }
                nums[i] = (1LL * nums[i] * diff[i]) % MOD;
            }
        }
        
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result ^= nums[i];
        }
        
        return result;
    }
};