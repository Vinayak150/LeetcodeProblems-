class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int l =0;
        int r = nums.size()-1;
        int maxPairSum =0;
        while(l<r){
            int pairSum =nums[l] + nums[r];
            maxPairSum = max(maxPairSum, pairSum);
            l++;
            r--;
        }
        return maxPairSum;
        
    }
};