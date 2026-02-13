class Solution {
public:

    struct pair_hash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<long long>()(
                ((long long)p.first << 32) ^ (long long)p.second
            );
        }
    };

    int longestBalanced(string s) {

        int n = s.size();
        int A = 0, B = 0, C = 0;
        int ans = 1;

        unordered_map<pair<int,int>, int, pair_hash> mapABC;
        unordered_map<pair<int,int>, int, pair_hash> mapAB;
        unordered_map<pair<int,int>, int, pair_hash> mapAC;
        unordered_map<pair<int,int>, int, pair_hash> mapBC;

        mapABC[{0,0}] = -1;
        mapAB[{0,0}] = -1;
        mapAC[{0,0}] = -1;
        mapBC[{0,0}] = -1;

        int run = 1;

        for (int i = 0; i < n; i++) {

            if (i > 0 && s[i] == s[i-1])
                run++;
            else
                run = 1;

            ans = max(ans, run);

            if (s[i] == 'a') A++;
            else if (s[i] == 'b') B++;
            else C++;

            int diffAB = A - B;
            int diffAC = A - C;
            int diffBC = B - C;

            pair<int,int> keyABC = {diffAB, diffAC};
            if (mapABC.count(keyABC))
                ans = max(ans, i - mapABC[keyABC]);
            else
                mapABC[keyABC] = i;

            pair<int,int> keyAB = {diffAB, C};
            if (mapAB.count(keyAB))
                ans = max(ans, i - mapAB[keyAB]);
            else
                mapAB[keyAB] = i;

            pair<int,int> keyAC = {diffAC, B};
            if (mapAC.count(keyAC))
                ans = max(ans, i - mapAC[keyAC]);
            else
                mapAC[keyAC] = i;

            pair<int,int> keyBC = {diffBC, A};
            if (mapBC.count(keyBC))
                ans = max(ans, i - mapBC[keyBC]);
            else
                mapBC[keyBC] = i;
        }

        return ans;
    }
};
