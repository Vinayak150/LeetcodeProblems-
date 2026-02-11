class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        // Precompute total distinct evens and odds remaining from each index
        vector<int> suffixEven(n+1, 0), suffixOdd(n+1, 0);
        unordered_set<int> seenEven, seenOdd;

        for (int i = n - 1; i >= 0; i--) {
            suffixEven[i] = suffixEven[i+1];
            suffixOdd[i] = suffixOdd[i+1];

            if (nums[i] % 2 == 0) {
                if (!seenEven.count(nums[i])) {
                    seenEven.insert(nums[i]);
                    suffixEven[i]++;
                }
            } else {
                if (!seenOdd.count(nums[i])) {
                    seenOdd.insert(nums[i]);
                    suffixOdd[i]++;
                }
            }
        }

        for (int l = 0; l < n; l++) {

            unordered_map<int,int> freq;
            int distinctEven = 0;
            int distinctOdd = 0;

            for (int r = l; r < n; r++) {

                freq[nums[r]]++;

                if (freq[nums[r]] == 1) {
                    if (nums[r] % 2 == 0)
                        distinctEven++;
                    else
                        distinctOdd++;
                }

                if (distinctEven == distinctOdd)
                    ans = max(ans, r - l + 1);

                // 🔥 Early stopping condition
                int remainingEven = suffixEven[r+1];
                int remainingOdd = suffixOdd[r+1];

                if (distinctEven > distinctOdd + remainingOdd)
                    break;

                if (distinctOdd > distinctEven + remainingEven)
                    break;
            }
        }

        return ans;
    }
};
