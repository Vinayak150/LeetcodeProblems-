class Solution {
public:
    int binaryGap(int n) {
        string bina= "";
        while(n>0){
            int r =n%2;
            bina =char(r+'0')+bina;
            n=n/2;
        }
        vector<int> one;
        for(int i=0;i< bina.length();i++){
            if(bina[i]=='1'){
                one.push_back(i);
            }
        }
        int m=0;
        for(int i=1;i<one.size();i++){
            int d =one[i]-one[i-1];
            m =max(m,d);
        }
        return m;
        
    }
};