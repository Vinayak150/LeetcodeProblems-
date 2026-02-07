class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int ta = 0;
        for( char c : s){
            if( c == 'a') ta++;
        }
        int lb = 0;
        int ra = ta;
        int a = n;
        for(int i =0; i <= n; i++){
            a=min(a,lb + ra);
            if(i < n){
                if(s[i]== 'b'){
                    lb++;
                }
                else{
                    ra--;
                }
            }
        }
        return a;
        
    }
};