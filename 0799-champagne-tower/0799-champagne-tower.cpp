class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(101,0);
        dp[0] = poured;
        for(int r =0; r< query_row; r++){
            for(int col = r; col>=0; col--){
                if(dp[col]>1.0){
                    double overflow = (dp[col]-1.0)/2.0;
                    dp[col]= overflow;
                    dp[col+1] += overflow;
                }
                else{
                    dp[col] =0;
                }
            }

        }
        return min(1.0, dp[query_glass]);
        
    }
};