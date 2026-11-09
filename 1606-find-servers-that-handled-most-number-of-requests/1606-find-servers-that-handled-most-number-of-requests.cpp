class Solution {
public:
    std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load) {
        std::vector<int> times(k, 0);
        std::set<int> idleServers;
        for (int i = 0; i < k; ++i) {
            idleServers.insert(i);
        }
        
        // Min-heap stores pairs of (end_time, server_id)
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minHeap;
        
        for (int i = 0; i < arrival.size(); ++i) {
            int currTime = arrival[i];
            
            // Free up servers that finished their tasks by currTime
            while (!minHeap.empty() && minHeap.top().first <= currTime) {
                idleServers.insert(minHeap.top().second);
                minHeap.pop();
            }
            
            if (idleServers.empty()) {
                continue; // Drop the request if all servers are busy
            }
            
            // Find the first server with index >= (i % k)
            auto it = idleServers.lower_bound(i % k);
            if (it == idleServers.end()) {
                it = idleServers.begin(); // Wrap around to index 0
            }
            
            int server = *it;
            idleServers.erase(it);
            
            times[server]++;
            minHeap.push({currTime + load[i], server});
        }
        
        int maxRequests = 0;
        for (int count : times) {
            maxRequests = std::max(maxRequests, count);
        }
        
        std::vector<int> ans;
        for (int i = 0; i < k; ++i) {
            if (times[i] == maxRequests) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
