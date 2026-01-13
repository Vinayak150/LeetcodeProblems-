class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

        double low = 0, high = 1e9;

        // Binary search for y
        for (int iter = 0; iter < 80; iter++) { // precision control
            double mid = (low + high) / 2.0;

            long double below = 0, above = 0;

            // Calculate areas
            for (auto& sq : squares) {
                long long y = sq[1];
                long long l = sq[2];
                long long top = y + l;

                if (mid <= y) {
                    // Entire square above
                    above += (long double)l * l;
                } else if (mid >= top) {
                    // Entire square below
                    below += (long double)l * l;
                } else {
                    // Line cuts the square
                    long double h_below = mid - y;
                    long double h_above = top - mid;

                    below += h_below * l;
                    above += h_above * l;
                }
            }

            // Adjust binary search
            if (below < above)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
