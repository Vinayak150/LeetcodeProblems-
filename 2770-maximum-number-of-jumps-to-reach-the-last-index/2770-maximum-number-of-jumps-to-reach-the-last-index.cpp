class Solution {
public:
    
    int solve(int i, vector<int>& nums, int target, vector<int>& dp) {
        int n = nums.size(); 

       
        if (dp[i] != -2) return dp[i];

       
        if (i == n - 1) return dp[i] = 0;

        
        int best = -1;

        
        for (int j = i + 1; j < n; j++) {
            
            
            if (abs(nums[j] - nums[i]) <= target) {
                
                
                int res = solve(j, nums, target, dp);
                
               
                if (res != -1) {
                    
                    best = max(best, 1 + res);
                }
            }
        }

        
        return dp[i] = best;
    }

    
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        
        
        vector<int> dp(n, -2); 

        
        return solve(0, nums, target, dp);
    }
};