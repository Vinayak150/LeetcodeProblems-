class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int L = n + m - 1;

        string word(L, '?');

        
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }

        
        for (char &c : word) {
            if (c == '?') c = 'a';
        }

     
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {

                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool fixed = false;

                  
                    for (int j = m - 1; j >= 0; j--) {
                        int pos = i + j;

                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c != word[pos]) {

                                char old = word[pos];
                                word[pos] = c;

                                
                                bool ok = true;

                                for (int k = max(0, pos - m + 1); k <= min(pos, n - 1); k++) {
                                    if (str1[k] == 'T') {
                                        for (int x = 0; x < m; x++) {
                                            if (word[k + x] != str2[x]) {
                                                ok = false;
                                                break;
                                            }
                                        }
                                        if (!ok) break;
                                    }
                                }

                                if (ok) {
                                    fixed = true;
                                    break;
                                }

                                word[pos] = old;
                            }
                        }

                        if (fixed) break;
                    }

                    if (!fixed) return "";
                }
            }
        }

        return word;
    }
};