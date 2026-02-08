class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {

        vector<long long> vin;   // using 'vin'

        for (int x : nums) {
            long long cur = x;

            // merge while the last element is equal
            while (!vin.empty() && vin.back() == cur) {
                cur += vin.back();
                vin.pop_back();
            }

            vin.push_back(cur);
        }

        return vin;
    }
};