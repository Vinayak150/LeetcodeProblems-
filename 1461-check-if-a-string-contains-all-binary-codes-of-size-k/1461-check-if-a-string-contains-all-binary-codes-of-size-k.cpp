class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> seen;
        for(int i=0;i+k<=s.length();i++){
            string sub =s.substr(i,k);
            seen.insert(sub);
        }
        return seen.size()==(1<<k);
        
    }
};