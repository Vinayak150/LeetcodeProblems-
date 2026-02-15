class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        int carry =0;
        string r ="";
        while(i>=0||j>=0||carry){
            int s = carry;
            if(i>=0){
                s +=a[i]-'0';
                i--;
            }
            if(j>=0){
                s+=b[j]-'0';
                j--;
            }
            r += (s%2)+'0';
            carry = s/2;
        }
        reverse(r.begin(),r.end());
        return r;
        
    }
};