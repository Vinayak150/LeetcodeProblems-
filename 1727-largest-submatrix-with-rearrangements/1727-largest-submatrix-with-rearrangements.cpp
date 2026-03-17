class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int m =matrix.size();
        int n =matrix[0].size();
        vector<int>height(n,0);
        int best =0;
        int area =0;
        for(int i =0; i<m;i++){
            for(int j =0; j<n;j++){
                if(matrix[i][j]==1){
                    height[j]+=1;
                }
                else {
                    height[j]=0;
                }
            }
            vector<int>temp=height;
            sort(temp.begin(),temp.end(),greater<int>());
            for(int j=0;j<n;j++){
                int a =temp[j]*(j+1);
                area=max(area,a);
            }
        }
        return area;
    }
};