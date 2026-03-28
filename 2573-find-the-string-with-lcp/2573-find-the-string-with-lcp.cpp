#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct DSU {
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;

            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    };

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }

       
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] != lcp[j][i]) return "";
            }
        }

        
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    dsu.unite(i, j);
                }
            }
        }

       
        unordered_map<int, char> compToChar;
        string word(n, '?');
        char nextChar = 'a';

        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);

            if (!compToChar.count(root)) {
                if (nextChar > 'z') return "";
                compToChar[root] = nextChar++;
            }

            word[i] = compToChar[root];
        }

        
        vector<vector<int>> calc(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    calc[i][j] = 1;
                    if (i + 1 < n && j + 1 < n) {
                        calc[i][j] += calc[i + 1][j + 1];
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (calc[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }

        return word;
    }
};