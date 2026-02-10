class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        for(int l =0;l<n;l++){
            unordered_set<int> even;
            unordered_set<int> odd;
            for(int r =l;r<n;r++){
                if(nums[r]%2 ==0){
                    even.insert(nums[r]);
                    
                }
                else{
                    odd.insert(nums[r]);
                }
                if(even.size()== odd.size()){
                    ans = max(ans,r-l+1);
                }
            }
        }
        return ans;
    }
};