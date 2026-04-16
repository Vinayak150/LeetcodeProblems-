class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();

        
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        
        for(int q : queries){

            int val = nums[q];
            vector<int>& v = mp[val];

            
            if(v.size() == 1){
                ans.push_back(-1);
                continue;
            }

            
            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();

            int best = INT_MAX;

            int prevIndex = v[(pos - 1 + v.size()) % v.size()];

            int d1 = abs(q - prevIndex);
            d1 = min(d1, n - d1);

            best = min(best, d1);

            
            int nextIndex = v[(pos + 1) % v.size()];

            int d2 = abs(q - nextIndex);
            d2 = min(d2, n - d2);

            best = min(best, d2);

            ans.push_back(best);
        }

        return ans;
    }
};