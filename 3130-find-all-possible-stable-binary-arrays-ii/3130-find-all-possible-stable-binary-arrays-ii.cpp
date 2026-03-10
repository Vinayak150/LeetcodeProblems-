class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1000000007;

        
        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));

        
        vector<vector<long long>> cum0(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> cum1(zero + 1, vector<long long>(one + 1, 0));

        
        for (int i = 0; i <= zero; ++i) {
            for (int j = 0; j <= one; ++j) {

               
                if (i > 0) {
                    if (j == 0) {
                        
                        dp0[i][0] = (i <= limit) ? 1LL : 0LL;
                    } else {
                       
                        int low = max(0, i - limit);
                        int high = i - 1;
                        long long sum = cum1[high][j];
                        if (low - 1 >= 0) sum = (sum - cum1[low - 1][j] + MOD) % MOD;
                        dp0[i][j] = sum % MOD;
                    }
                } else {
                    dp0[i][j] = 0;
                }

                // update prefix cum0 for this row i (prefix over j)
                if (j == 0) cum0[i][j] = dp0[i][j] % MOD;
                else cum0[i][j] = (cum0[i][j - 1] + dp0[i][j]) % MOD;

                // --- compute dp1[i][j] (ending with 1) ---
                if (j > 0) {
                    if (i == 0) {
                        
                        dp1[0][j] = (j <= limit) ? 1LL : 0LL;
                    } else {
                        
                        int low = max(0, j - limit);
                        int high = j - 1;
                        long long sum = cum0[i][high];
                        if (low - 1 >= 0) sum = (sum - cum0[i][low - 1] + MOD) % MOD;
                        dp1[i][j] = sum % MOD;
                    }
                } else {
                    dp1[i][j] = 0;
                }

                
                if (i == 0) cum1[i][j] = dp1[i][j] % MOD;
                else cum1[i][j] = (cum1[i - 1][j] + dp1[i][j]) % MOD;
            }
        }

        long long ans = (dp0[zero][one] + dp1[zero][one]) % MOD;
        return (int)ans;
    }
};