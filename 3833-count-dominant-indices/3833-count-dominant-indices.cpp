class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // Loop for each index i
        for (int i = 0; i < n; i++) {

            // Last index cannot be dominant
            if (i == n - 1)
                continue;

            int sum = 0;
            int elements = 0;

            // Calculate sum of elements to the right of i
            for (int j = i + 1; j < n; j++) {
                sum += nums[j];
                elements++;
            }

            double average = (double)sum / elements;

            // Check dominant condition
            if (nums[i] > average) {
                count++;
            }
        }

        return count;
    }
};