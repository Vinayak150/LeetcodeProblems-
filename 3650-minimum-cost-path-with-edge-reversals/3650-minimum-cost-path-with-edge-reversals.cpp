

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // Build the graph using Adjacency List
        // adj[u] = {neighbor, weight}
        vector<vector<pair<int, int>>> adj(n);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            // 1. Normal Path: u -> v cost w
            adj[u].push_back({v, w});
            
            // 2. Reversed Path: v -> u cost 2*w
            // We can reverse an incoming edge (u->v) at v to go back to u
            adj[v].push_back({u, w * 2});
        }
        
        // Standard Queue for SPFA (replaces Priority Queue)
        queue<int> q;
        q.push(0);
        
        // Distance array, initialized to a large value
        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        dist[0] = 0;
        
        // Optimization: Boolean array to check if node is currently in queue
        // This prevents adding the same node multiple times to the queue unnecessarily
        vector<bool> inQueue(n, false);
        inQueue[0] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false; // Node is processed, remove from tracking
            
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                // Relaxation Step:
                // If we found a cheaper way to reach v through u
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    
                    // If v is not already waiting in the queue, add it
                    if (!inQueue[v]) {
                        q.push(v);
                        inQueue[v] = true;
                    }
                }
            }
        }
        
        if (dist[n - 1] == INF) return -1;
        return (int)dist[n - 1];
    }
};