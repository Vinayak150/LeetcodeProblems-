class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> r;
        for(int h =0; h<=11;h++){
            for(int m =0; m<=59;m++){
                int hb = __builtin_popcount(h);
                int mb = __builtin_popcount(m);
                int tb = hb + mb;
                if(tb == turnedOn){
                    string time = to_string(h)+':';
                    if(m < 10){
                        time +="0";
                    }
                    time += to_string(m);
                    r.push_back(time);
                }
            }
        }
        return r;
         
        
    }
};