class Solution {
public:
    char invert(char c){
        if(c=='0'){
            return '1';
        }
        else{
            return '0';
        }

    }
    char solve(int n,long long k){
        if(n==1){
            return '0';
        }
        long long length =(1LL<<n)-1;
        long long mid =(1LL <<(n-1));
        if(k==mid){
            return '1';
        }
        if(k<mid){
            return solve(n-1,k);
        } 
        long long mirrorindex =length -k+1;
        char res =solve(n-1,mirrorindex);
        return invert(res);
           }
    char findKthBit(int n, int k) {
        return solve(n,k);
        
    }
};