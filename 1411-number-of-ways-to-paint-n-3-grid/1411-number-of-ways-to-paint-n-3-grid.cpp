class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> rows;
    vector<vector<int>> dp;
    int n;

    void generateRows(){
        for( int a =0;a <3;a++){
            for(int b=0; b<3;b++){
                for(int c =0;c<3;c++){
                    if(a != b && b != c){
                        rows.push_back({a,b,c});

                    }
                }
            }
        }
    }

    bool compatible(vector<int>& r1, vector<int>& r2){
        for( int i =0;i < 3; i++){
            if ( r1[i]==r2[i]) return false;
        }
        return true;
    }

    int dfs(int row, int prev){
        if( row == n) return 1;

        if( dp[row][prev]!= -1)
        return dp[row][prev];

        long long ways = 0;
        for(int i =0; i< rows.size(); i++){
            if (compatible(rows[prev], rows[i])) {
                ways = (ways + dfs(row + 1, i)) % MOD;
            }
        }

        return dp[row][prev] = ways;
    }

    int numOfWays(int n_) {
        n = n_;
        generateRows();
        dp.assign(n, vector<int>(rows.size(), -1));

        long long ans = 0;

        for( int i=0; i < rows.size(); i++){
            ans = ( ans + dfs(1,i)) % MOD;
        }

        return ans;
        
    }
};