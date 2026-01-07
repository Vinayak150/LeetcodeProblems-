class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans (n+1);

        for(int i =0;i <= n; i++){
            int x =i;
            int count = 0;
            while(x >0){
                count += x%2;
                x =x/2;
            }

            ans[i] = count;
        }
        
        return ans;
    }
};