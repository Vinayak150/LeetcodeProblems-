
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto canReduce = [&](long long mid) {
            long long totalReduction = 0;
            for (int t : workerTimes) {
                double val = 2.0 * mid / t;
                long long x = (-1.0 + sqrt(1.0 + 4.0 * val)) / 2.0;
                totalReduction += x;
                if (totalReduction >= mountainHeight) return true;
            }
            return totalReduction >= mountainHeight;
        };

        long long low = 1;
        long long min_t = *min_element(workerTimes.begin(), workerTimes.end());
        long long high = min_t * (long long)mountainHeight * (mountainHeight + 1) / 2;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canReduce(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};