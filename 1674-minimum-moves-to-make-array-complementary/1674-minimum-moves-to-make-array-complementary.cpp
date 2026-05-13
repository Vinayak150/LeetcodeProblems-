class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int pairs = n / 2;

        
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < pairs; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b) + 1;
            int high = max(a, b) + limit;
            int sum = a + b;

            
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            
            diff[low] -= 1;
            diff[high + 1] += 1;

            
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = INT_MAX;
        int curr = 0;

         
        for (int s = 2; s <= 2 * limit; s++) {
            curr += diff[s];
            ans = min(ans, curr);
        }

        return ans;
    }
};