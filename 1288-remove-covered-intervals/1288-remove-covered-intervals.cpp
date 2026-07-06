class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        // Sort by increasing start.
        // If starts are equal, larger end first.
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {

                 if (a[0] == b[0])
                     return a[1] > b[1];

                 return a[0] < b[0];
             });

        int remaining = 0;

        int maxEnd = 0;

        for (auto& interval : intervals) {

            // If current interval extends beyond all previous ones,
            // it cannot be covered.
            if (interval[1] > maxEnd) {

                remaining++;
                maxEnd = interval[1];
            }
        }

        return remaining;
    }
};