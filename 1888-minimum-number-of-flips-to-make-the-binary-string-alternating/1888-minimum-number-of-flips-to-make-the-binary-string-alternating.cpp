class Solution {
public:
    int minFlips(string s) {

        int n = s.size();

        // Double the string to simulate rotations
        string doubled = s + s;

        
        string alt1 = ""; // 010101...
        string alt2 = ""; // 101010...

        
        for(int i = 0; i < 2*n; i++) {

            if(i % 2 == 0) {
                alt1 += '0';
                alt2 += '1';
            }
            else {
                alt1 += '1';
                alt2 += '0';
            }
        }

        int diff1 = 0; 
        int diff2 = 0;  

        int left = 0;
        int ans = INT_MAX;

    
        for(int right = 0; right < 2*n; right++) {

            
            if(doubled[right] != alt1[right])
                diff1++;

            if(doubled[right] != alt2[right])
                diff2++;

            // Maintain window size n
            if(right - left + 1 > n) {

                if(doubled[left] != alt1[left])
                    diff1--;

                if(doubled[left] != alt2[left])
                    diff2--;

                left++;
            }

            if(right - left + 1 == n)
                ans = min(ans, min(diff1, diff2));
        }

        return ans;
    }
};