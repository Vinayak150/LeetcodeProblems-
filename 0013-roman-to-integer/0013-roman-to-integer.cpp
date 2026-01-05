class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> val = {
            {'I',1},{'V',5},{'X',10},{'L',50},
            {'C',100},{'D',500},{'M',1000}
        };
        int n = s.size();
        int total = 0;
        int prev = 0; // value of previously processed symbol (to the right)
        for (int i = n - 1; i >= 0; --i) {
            int cur = val[s[i]];
            if (cur < prev) total -= cur;
            else {
                total += cur;
                prev = cur;
            }
        }
        return total;
    }
};