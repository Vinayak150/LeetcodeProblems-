class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(words[i]==target){
                int d=abs(i-startIndex);
                int c=n-d;
                int di=min(d,c);
                ans=min(ans,di);

            }
        }
        if(ans==INT_MAX)return -1;

        return ans;
        
    }
};