class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,pair<int,int>>mp;
        int a=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(mp.count(x)){
                auto &p=mp[x];
                int last=p.first;
                int second_last=p.second;
                if(second_last!=-1){
                    int dist=2*(i-second_last);
                    a=min(a,dist);
                }
                p.second=last;
                p.first=i;
            }
            else{
                mp[x]={i,-1};
            }
        }
        return a==INT_MAX?-1:a;
    }
};