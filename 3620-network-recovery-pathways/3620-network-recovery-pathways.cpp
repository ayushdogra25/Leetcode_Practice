class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        
        vector<vector<array<int, 2>>> adj(n);
        vector<int> in_degree_orig(n, 0);
        int max_cost = -1;
        
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (online[u] && online[v]) {
                adj[u].push_back({v, w});
                max_cost = max(max_cost, w);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (const auto& edge : adj[i]) {
                in_degree_orig[edge[0]]++;
            }
        }
        
        auto check = [&](int min_edge_cost) -> bool {
            vector<long long> dist(n, -1);
            dist[0] = 0;
            
            vector<int> in_degree = in_degree_orig;
            queue<int> q;
            for (int i = 0; i < n; ++i) {
                if (in_degree[i] == 0) {
                    q.push(i);
                }
            }
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                long long current_dist = dist[u];
                
                for (const auto& edge : adj[u]) {
                    int v = edge[0];
                    int w = edge[1];
                    
                    if (w >= min_edge_cost && current_dist != -1) {
                        if (dist[v] == -1 || current_dist + w < dist[v]) {
                            dist[v] = current_dist + w;
                        }
                    }
                    
                    if (--in_degree[v] == 0) {
                        q.push(v);
                    }
                }
            }
            
            return dist[n - 1] != -1 && dist[n - 1] <= k;
        };
        
        int low = 0, high = max_cost, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};