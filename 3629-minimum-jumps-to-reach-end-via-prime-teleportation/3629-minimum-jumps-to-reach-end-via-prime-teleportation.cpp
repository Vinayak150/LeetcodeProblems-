class Solution {
public:

    // Check if number is prime
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    // Get prime factors (unique)
    vector<int> getPrimeFactors(int x) {
        vector<int> factors;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                factors.push_back(i);
                while (x % i == 0) x /= i;
            }
        }

        if (x > 1) factors.push_back(x);

        return factors;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Build prime → indices map
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            vector<int> factors = getPrimeFactors(nums[i]);

            for (int f : factors) {
                mp[f].push_back(i);
            }
        }

        // Step 2: BFS
        queue<pair<int,int>> q; // {index, steps}
        vector<bool> visited(n, false);

        q.push({0,0});
        visited[0] = true;

        while (!q.empty()) {

            int i = q.front().first;
            int steps = q.front().second;
            q.pop();

            // reached end
            if (i == n - 1) return steps;

            // -------- Adjacent moves --------
            if (i + 1 < n && !visited[i + 1]) {
                visited[i + 1] = true;
                q.push({i + 1, steps + 1});
            }

            if (i - 1 >= 0 && !visited[i - 1]) {
                visited[i - 1] = true;
                q.push({i - 1, steps + 1});
            }

            // -------- Prime teleport --------
            if (isPrime(nums[i])) {

                int p = nums[i];

                for (int idx : mp[p]) {
                    if (!visited[idx]) {
                        visited[idx] = true;
                        q.push({idx, steps + 1});
                    }
                }

                // IMPORTANT: avoid re-processing
                mp[p].clear();
            }
        }

        return -1;
    }
};