class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), mod = 1e9+7;
        int B = sqrt(n) + 1;

        vector<vector<pair<int,int>>> small(B);
        
     
        for(auto &q : queries){
            int l=q[0], r=q[1], k=q[2], v=q[3];
            if(k < B) small[k].push_back({l<<20 | r, v});
            else{
                for(int i=l;i<=r;i+=k)
                    nums[i] = (1LL * nums[i] * v) % mod;
            }
        }

       
        for(int k=1;k<B;k++){
            if(small[k].empty()) continue;

            vector<long long> mul(n,1);

            for(auto &p: small[k]){
                int l = p.first>>20;
                int r = p.first & ((1<<20)-1);
                int v = p.second;

                for(int i=l;i<=r;i+=k)
                    mul[i] = (mul[i]*v)%mod;
            }

            for(int i=0;i<n;i++)
                nums[i] = (1LL * nums[i] * mul[i])%mod;
        }

        int ans=0;
        for(int x:nums) ans ^= x;
        return ans;
    }
};