class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        int n = nums.size();

        
        unordered_set<string> st(nums.begin(), nums.end());

        

        for(int num = 0; num < (1 << n); num++) {

            

            string candidate = "";

            for(int i = n - 1; i >= 0; i--) {

                if(num & (1 << i))
                    candidate += '1';
                else
                    candidate += '0';
            }

            

            if(st.find(candidate) == st.end())
                return candidate;
        }

        return "";
    }
};