class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int> arr; 
        
        
        for (auto &row : grid) {
            for (int val : row) {
                arr.push_back(val);
            }
        }
        
       
        int remainder = arr[0] % x;
        
        for (int val : arr) {
            if (val % x != remainder) {
                return -1; 
            }
        }
        
        
        sort(arr.begin(), arr.end());
        
       
        int n = arr.size();
        int median = arr[n / 2];
        
        
        int operations = 0;
        
        for (int val : arr) {
            operations += abs(val - median) / x;
        }
        
        return operations;
    }
};