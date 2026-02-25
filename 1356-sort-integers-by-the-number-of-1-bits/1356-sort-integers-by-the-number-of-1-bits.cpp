class Solution {
public:
int countbits(int n){
    int count =0;
    while(n>0){
        count+=(n&1);
        n=n>>1;

    }
    return count;
}

    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> temp;
        for(int num:arr){
            int bit=countbits(num);
            temp.push_back({bit,num});
        }
        sort(temp.begin(),temp.end());
        vector<int> res;

        for(auto p: temp){
            res.push_back(p.second);
        }

        return res;

        
    }
};