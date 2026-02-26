class Solution {
public:
    void Addone(string &s){
        int n =s.size();
        int carry =1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1' && carry ==1){
                s[i]='0';
                carry=1;

            }
            else if(s[i]=='0' && carry == 1){
                s[i]='1';
                carry =0;
                break;
            }
        }
        if(carry==1){
            s='1'+s;
        }
    }
 
    int numSteps(string s) {
        int step =0;
        while(s!="1")
        {
            if(s.back()=='0'){
                s.pop_back();
            }
            else{
                Addone(s);
            }
            step++;


        }
        return step;
        
    }
};