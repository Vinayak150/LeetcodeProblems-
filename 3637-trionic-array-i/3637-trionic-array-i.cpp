class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        for(int p =1; p <= n-3;p++){
            for(int q =p +1;q<=n-2;q++){
                bool ok = true;
                for(int i =0; i< p;i++){
                    if(nums[i]>=nums[i+1]){
                        ok =false;
                        break;
                    }
                }
                if(!ok) continue;

                for(int i = p; i<q;i++){
                    if(nums[i]<=nums[i+1]){
                        ok = false;
                        break;
                    }
                }
                if(!ok ) continue;
                for(int i =q; i< n-1; i++){
                    if(nums[i]>= nums[i+1]){
                        ok = false;
                        break;
                    }
                }
                if(!ok) continue;
                return true;
            }
        }
        return false;

        
    }
};