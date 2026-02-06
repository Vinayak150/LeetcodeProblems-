class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        int maxLen = 1;
        int j =0;
        for(int i = 0; i < n; i++){
            while(j < n && (long long)nums[j] <= (long long)nums[i]*k){
                j++;
            }
            int current = j - i;
            maxLen = max(maxLen,current);
        }
        return n - maxLen;
    }
};