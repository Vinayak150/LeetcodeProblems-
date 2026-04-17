class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> lastIndex; 
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            
            if (lastIndex.count(x)) {
                ans = min(ans, i - lastIndex[x]);
            }

            
            lastIndex[reverseNum(x)] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};