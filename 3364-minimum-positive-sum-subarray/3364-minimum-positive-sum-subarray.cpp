class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int min_sum = -1;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int current_sum = 0;
            for (int j = i; j < n; ++j) {
                current_sum += nums[j];
                int len = j - i + 1;
                
                if (len >= l && len <= r) {
                    if (current_sum > 0) {
                        if (min_sum == -1 || current_sum < min_sum) {
                            min_sum = current_sum;
                        }
                    }
                }
                
                if (len >= r) {
                    break;
                }
            }
        }
        
        return min_sum;
    }
};