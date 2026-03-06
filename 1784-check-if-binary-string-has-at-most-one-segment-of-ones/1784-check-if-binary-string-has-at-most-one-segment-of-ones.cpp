class Solution {
public:
    bool checkOnesSegment(string s) {
        
        int seg =0;
        int n=s.size();
        for(int i =0; i<n;i++){
            if(s[i]=='1'){
                seg++;
                while(i<n&&s[i]=='1'){
                    i++;
                }
                if(seg >1){
                    return false;
                }
            }
        }
        return true;
    }
};