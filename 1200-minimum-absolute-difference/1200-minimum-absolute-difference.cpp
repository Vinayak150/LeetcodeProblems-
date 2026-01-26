class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        int n = arr.size();

        // Step 2: Find the minimum absolute difference
        int minDiff = INT_MAX;
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        // Step 3: Collect all pairs with minDiff
        vector<vector<int>> result;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == minDiff) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }

        return result;
    }
};
