class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>fr;
        for(int i=0;i<nums.size();i++){
            fr[nums[i]]++;

            if(fr[nums[i]]>1){
                return nums[i];
            }
        }
        return -1;
        
    }
};