#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                     vector<int>& healths,
                                     string directions) {
        int n = positions.size();

        
        vector<tuple<int,int,char,int>> robots;
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        
        sort(robots.begin(), robots.end());

        
        vector<int> st;

        vector<int> curHealth(n);
        vector<char> dir(n);
        vector<int> originalIndex(n);

        for (int i = 0; i < n; i++) {
            auto [pos, h, d, idx] = robots[i];
            curHealth[i] = h;
            dir[i] = d;
            originalIndex[i] = idx;
        }

        
        for (int i = 0; i < n; i++) {
            if (dir[i] == 'R') {
                
                st.push_back(i);
            } else {
                
                int leftHealth = curHealth[i];

                
                while (!st.empty() && leftHealth > 0) {
                    int rIdx = st.back();

                    if (curHealth[rIdx] < leftHealth) {
                        
                        leftHealth--;
                        curHealth[rIdx] = 0;
                        st.pop_back();
                    } else if (curHealth[rIdx] == leftHealth) {
                        // Both die
                        curHealth[rIdx] = 0;
                        leftHealth = 0;
                        st.pop_back();
                        break;
                    } else {
                        // Left robot dies
                        curHealth[rIdx]--;
                        leftHealth = 0;
                        break;
                    }
                }

                curHealth[i] = leftHealth;
            }
        }

       
        vector<pair<int,int>> survivors; // {original_index, health}
        for (int i = 0; i < n; i++) {
            if (curHealth[i] > 0) {
                survivors.push_back({originalIndex[i], curHealth[i]});
            }
        }

        sort(survivors.begin(), survivors.end());

        vector<int> ans;
        for (auto &p : survivors) {
            ans.push_back(p.second);
        }

        return ans;
    }
};