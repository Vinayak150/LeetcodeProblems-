class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int Z = 0;
        
        // Count zeros
        for(char c : s) {
            if(c == '0') Z++;
        }
        
        // Already all ones
        if (Z == 0) return 0;
        
        
        if (k == n) {
            if (Z == n) return 1;
            return -1;
        }
        
        long long min_m = -1;
        
     
        if (Z % 2 == 0) {
            long long m1_k = (Z + k - 1) / k;                
            long long m1_nk = (Z + (n - k) - 1) / (n - k);   // from m*(n-k) >= Z
            
            long long m1 = std::max(m1_k, m1_nk);
            
            
            if (m1 % 2 != 0) m1++;
            min_m = m1;
        }
        
       
        if (k % 2 == Z % 2) {
            long long m2_k = (Z + k - 1) / k;                         // 
            long long m2_nk = ((n - Z) + (n - k) - 1) / (n - k);      // 
            
            long long m2 = std::max(m2_k, m2_nk);
            
           
            if (m2 % 2 == 0) m2++;
            
            if (min_m == -1 || m2 < min_m) {
                min_m = m2;
            }
        }
        
        return min_m;
    }
};