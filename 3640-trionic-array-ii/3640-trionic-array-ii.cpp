class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        // A trionic subarray requires at least 4 elements (indices l, p, q, r are distinct)
        if (n < 4) return -1; 

        // Use a safe large negative number that won't underflow when adding values
        // Minimum possible sum is roughly -10^9 * 10^5 = -10^14. 
        const long long INF = 1e15; 
        
        // Initialize states
        // inc: Max sum of strictly increasing subarray ending at i (len >= 1)
        long long inc = nums[0];
        
        // up: Max sum of strictly increasing subarray ending at i (len >= 2)
        // Satisfies nums[l...p]
        long long up = -INF;
        
        // down: Max sum of Up->Down ending at i (down len >= 2)
        // Satisfies nums[l...p...q]
        long long down = -INF;
        
        // tri: Max sum of Up->Down->Up ending at i (last up len >= 2)
        // Satisfies nums[l...p...q...r]
        long long tri = -INF;
        
        long long ans = -INF;

        for (int i = 1; i < n; ++i) {
            long long val = nums[i];
            long long prev = nums[i-1];

            // Temporary variables for the next state
            long long next_inc = -INF;
            long long next_up = -INF;
            long long next_down = -INF;
            long long next_tri = -INF;

            // 1. Update 'inc' (Start or extend increasing sequence)
            if (val > prev) {
                // Either extend previous increasing or restart here if previous sum was negative
                next_inc = max(val, inc + val);
            } else {
                // Must restart if not strictly increasing
                next_inc = val;
            }

            // 2. Update 'up' (Transition from length 1 to length 2)
            // We need a strictly increasing sequence of at least length 2.
            if (val > prev) {
                // Can only extend a valid increasing sequence from the previous step
                if (inc > -INF) {
                    next_up = inc + val;
                }
            }

            // 3. Update 'down' (Transition from Up or extend Down)
            if (val < prev) {
                // Option A: Extend an existing Down sequence
                if (down > -INF) {
                    next_down = max(next_down, down + val);
                }
                
                // Option B: Transition from a completed Up sequence (Peak)
                // The Up sequence must have length >= 2 (state 'up')
                if (up > -INF) {
                    // Transition creates a down segment of length 2 (indices i-1, i)
                    next_down = max(next_down, up + val);
                }
            }

            // 4. Update 'tri' (Transition from Down or extend Trionic)
            if (val > prev) {
                // Option A: Extend an existing Trionic sequence (Second Up phase)
                if (tri > -INF) {
                    next_tri = max(next_tri, tri + val);
                }
                
                // Option B: Transition from a completed Down sequence (Valley)
                if (down > -INF) {
                    // Transition creates a 2nd up segment of length 2 (indices i-1, i)
                    next_tri = max(next_tri, down + val);
                }
            }

            // Update states for the next iteration
            inc = next_inc;
            up = next_up;
            down = next_down;
            tri = next_tri;

            // Update global maximum if we have a valid trionic subarray
            if (tri > ans) {
                ans = tri;
            }
        }

        // Return ans if found, otherwise -1 (or appropriate failure value based on platform spec)
        // Based on the problem type, if no such subarray exists, we usually return a sentinel.
        // However, Example 1 result is negative (-4), so we return the max found.
        if (ans == -INF) return -1;
        return ans;
    }
};