class Solution {
public:
    string makeLargestSpecial(string s) {
        int c =0;
        int start =0;
        vector<string>subs;
        for(int i =0; i <s.length();i++){
            if(s[i]=='1'){
                c++;
            }
            else{
                c--;
            }
            if(c==0){
                string in =s.substr(start+1,i-start-1);
                in = makeLargestSpecial(in);
                subs.push_back("1"+ in +"0");
                start = i+1;

            }
        }
        sort(subs.begin(),subs.end(),greater<string>());
        string r ="";
        for(string str:subs)
            r += str;
        return r;

        
        
    }
};