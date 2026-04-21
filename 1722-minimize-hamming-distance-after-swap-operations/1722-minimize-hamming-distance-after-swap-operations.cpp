class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unite(int a, int b){
        int roota=find(a);
        int rootb=find(b);

        if(roota!=rootb){
            parent[roota]=rootb;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto &edge: allowedSwaps){
            int u=edge[0];
            int v=edge[1];
            unite(u,v);
        }
        unordered_map<int,vector<int>> groups;
        for(int i=0;i<n;i++){
            int root=find(i);
            groups[root].push_back(i);
        }
        int hamdist=0;
        for(auto &group:groups){
            vector<int>&indices=group.second;
            unordered_map<int,int>freq;
            for(int idx:indices){
                freq[source[idx]]++;
            }

            for(int idx:indices){
                int targetvalue=target[idx];
                if(freq[targetvalue]>0){
                    freq[targetvalue]--;
                }
                else{
                    hamdist++;
                }
            }
        }
        return hamdist;
        
    }
};