class Solution {
public:
    int mirrorDistance(int n) {
        int rev=0, temp=n;
        while(temp){
            rev=rev*10+temp%10;
            temp/=10;
        }
        return abs(n-rev);
        
    }
};