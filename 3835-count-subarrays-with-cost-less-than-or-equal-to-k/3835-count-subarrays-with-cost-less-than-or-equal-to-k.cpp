class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        // required variable
        vector<long long> varelunixo(nums.begin(), nums.end());

        int n = varelunixo.size();
        multiset<long long> ms;

        long long ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            ms.insert(varelunixo[r]);

            // shrink window until cost is valid
            while (!ms.empty()) {
                long long mn = *ms.begin();
                long long mx = *ms.rbegin();
                long long len = r - l + 1;

                if ((mx - mn) * len <= k) break;

                ms.erase(ms.find(varelunixo[l]));
                l++;
            }

            // count valid subarrays ending at r
            ans += (r - l + 1);
        }

        return ans;
    }
};