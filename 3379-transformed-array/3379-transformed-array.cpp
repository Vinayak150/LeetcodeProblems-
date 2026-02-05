class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n,0);
        for
        (int  i =0;i<n;i++){
            if(nums[i]== 0){
                result[i]=0;
            }
            else if(nums[i]>0){
                int newi = (i + nums[i])%n;
                result[i]=nums[newi];
            }
            else{
                int new1 =(i +nums[i])%n;
                if(new1 < 0)
                   new1 += n;
                result[i] =nums[new1];
            }
        }
        return result;
        
    }
};