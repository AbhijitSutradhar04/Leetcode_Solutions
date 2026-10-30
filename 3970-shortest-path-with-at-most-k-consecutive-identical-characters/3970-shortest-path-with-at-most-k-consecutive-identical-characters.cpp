using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Build the adjacency list: adj[u] = {(v, weight), ...}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        // Define infinity for distance initialization
        const int INF = 1e9 + 7;
        
        // dist[node][consecutive_count] stores the minimum weight to reach `node`
        // where the current run of identical characters is `consecutive_count`.
        // The count can range from 1 to k.
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));
        
        // Min-heap priority queue storing tuple: (current_distance, node, consecutive_count)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        
        // Base case: Starting at node 0, the first character counts as 1 consecutive character
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        
        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();
            
            // If we found a shorter path to this state already, skip it
            if (d > dist[u][count]) continue;
            
            // If we reached the destination node, return the distance
            if (u == n - 1) return d;
            
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                int next_count = 0;
                if (labels[v] == labels[u]) {
                    next_count = count + 1;
                } else {
                    next_count = 1;
                }
                
                // If moving to node v violates the condition, this path is invalid
                if (next_count > k) continue;
                
                // Relaxation step
                if (d + weight < dist[v][next_count]) {
                    dist[v][next_count] = d + weight;
                    pq.push({dist[v][next_count], v, next_count});
                }
            }
        }
        
        // If the destination node is unreachable under the rules, return -1
        return -1;
    }
};