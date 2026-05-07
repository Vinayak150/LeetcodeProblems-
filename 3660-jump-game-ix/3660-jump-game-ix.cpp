class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        // pref[i] = maximum of nums[0..i]
        vector<int> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], nums[i]);
        }

        // suf[i] = minimum of nums[i..n-1]
        vector<int> suf(n);
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = min(suf[i + 1], nums[i]);
        }

        vector<int> ans(n);

        int start = 0;          // start of current component
        int segMax = nums[0];   // max inside current component

        for (int i = 0; i < n - 1; i++) {
            segMax = max(segMax, nums[i]);

            // No edge crosses the cut after i
            if (pref[i] <= suf[i + 1]) {
                for (int j = start; j <= i; j++) {
                    ans[j] = segMax;
                }
                start = i + 1;
                if (start < n) segMax = nums[start];
            }
        }

        // Final segment
        segMax = max(segMax, nums[n - 1]);
        for (int j = start; j < n; j++) {
            ans[j] = segMax;
        }

        return ans;
    }
};