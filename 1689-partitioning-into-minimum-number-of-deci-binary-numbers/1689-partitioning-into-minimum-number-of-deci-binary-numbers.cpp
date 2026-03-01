class Solution {
public:
    int minPartitions(string n) {
        int m =0;
        for(char c:n){
            int d =c-'0';
            m =max(m,d);
            if(m==9)
               return 9;
        }
        return m;
    }
};