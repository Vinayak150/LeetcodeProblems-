class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) { // renamed
        int ops = 0;
        auto nonDec = [&](const vector<int>&a) -> bool {
            for (int i = 1; i < (int)a.size(); ++i)
                if (a[i] < a[i-1]) return false;
            return true;
        };
        if (nonDec(nums)) return 0;
        while (!nonDec(nums) && nums.size() > 1) {
            int n = nums.size();
            int bestIdx = 0;
            int bestSum = nums[0] + nums[1];
            for (int i = 1; i < n-1; ++i) {
                int s = nums[i] + nums[i+1];
                if (s < bestSum) {
                    bestSum = s;
                    bestIdx = i;
                }
            }
            nums[bestIdx] = bestSum;
            nums.erase(nums.begin() + bestIdx + 1);
            ++ops;
        }
        return ops;
    }
};