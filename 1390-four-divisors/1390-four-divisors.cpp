class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        
        for (int num : nums) {
            int divisorCount = 0;   
            int divisorSum = 0;     
           
            for (int d = 1; d * d <= num; d++) {
                if (num % d == 0) {
                    int other = num / d;

                   
                    divisorCount++;
                    divisorSum += d;

                    
                    if (other != d) {
                        divisorCount++;
                        divisorSum += other;
                    }

                    
                    if (divisorCount > 4) {
                        break;
                    }
                }
            }

           
            if (divisorCount == 4) {
                totalSum += divisorSum;
            }
        }

        return totalSum;
    }
};