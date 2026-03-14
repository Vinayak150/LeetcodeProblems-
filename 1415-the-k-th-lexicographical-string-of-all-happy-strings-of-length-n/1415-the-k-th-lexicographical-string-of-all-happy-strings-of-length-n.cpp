#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        if (n <= 0) return "";
        long long total = 3LL * (1LL << max(0, n-1));
        if (k > total) return "";
        string res; res.reserve(n);
        char prev = 0;
        for (int pos = 0; pos < n; ++pos) {
            int rem = n - pos - 1;
            long long block = 1LL << max(0, rem);
            for (char c : {'a','b','c'}) {
                if (c == prev) continue;
                if (block >= k) { res.push_back(c); prev = c; break; }
                k -= block;
            }
        }
        return res;
    }
};