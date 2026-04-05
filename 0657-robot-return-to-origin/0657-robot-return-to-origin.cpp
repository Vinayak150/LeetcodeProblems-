class Solution {
public:
    bool judgeCircle(string moves) {
        long long x=0;
        long long y=0;

        for( char c:moves ){
            if (c=='U'){
                y=y+1;
            }
            else if(c=='D'){
                    y=y-1;
                }
            else if(c=='L'){
                x=x-1;
            }
            else if(c=='R'){
                x=x+1;
            }
        }
        if (x==0&&y==0){
            return true;
        }
        else{
            return false;
        }
            
        
        
    }
};