class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        // Store all prefixes from arr1
        for (int num : arr1) {
            string s = to_string(num);

            int val = 0;
            for (char c : s) {
                val = val * 10 + (c - '0');
                prefixes.insert(val);
            }
        }

        int ans = 0;

        // Check prefixes from arr2
        for (int num : arr2) {
            string s = to_string(num);

            int val = 0;
            for (int i = 0; i < s.size(); i++) {
                val = val * 10 + (s[i] - '0');

                if (prefixes.count(val))
                    ans = max(ans, i + 1);
            }
        }

        return ans;
    }
};