class Solution {
public:
    int minOperations(string s) {
        
        int n =s.size();
        string p1 ="";
        string p2 ="";
        for(int i=0; i<n;i++){
            if(i%2==0){
                p1+='0';
                p2+='1';
            }
            else{
                p1 +='1';
                p2+='0';

            }
        }
        int change1 =0;
        int change2 =0;
        for(int i=0;i<n;i++){
            if(s[i]!=p1[i]){
                change1++;
            }
            if(s[i]!=p2[i]){
                change2++;
            }
        }
        return min(change1,change2);
    }
};