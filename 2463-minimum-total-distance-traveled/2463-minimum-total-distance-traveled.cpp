class Solution {
public:
    long long dfs(int i, int j, vector<int>& robot, vector<vector<int>>& factory,
                  vector<vector<long long>>& memo) {
        int n = robot.size();
        int m = factory.size();

        
        if (i == n) return 0;

        
        if (j == m) return (1LL << 60);

        
        if (memo[i][j] != -1) return memo[i][j];

        long long ans = (1LL << 60);

       
        ans = min(ans, dfs(i, j + 1, robot, factory, memo));

        long long cost = 0;
        int factoryPos = factory[j][0];
        int limit = factory[j][1];

        
        for (int k = 1; k <= limit && i + k <= n; k++) {
          
            cost += llabs((long long)robot[i + k - 1] - factoryPos);

            
            long long next = dfs(i + k, j + 1, robot, factory, memo);

         
            ans = min(ans, cost + next);
        }

        return memo[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort robots and factories by position
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        
        vector<vector<long long>> memo(n + 1, vector<long long>(m + 1, -1));

        return dfs(0, 0, robot, factory, memo);
    }
};