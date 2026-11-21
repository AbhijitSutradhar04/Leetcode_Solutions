using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        // Tracks the most recent ancestor node for each character 'a'-'z'
        vector<int> lastSeen(26, -1);
        vector<int> newParent = parent;

        // Pass 1: Find the closest matching ancestor for every node
        findNewParents(0, adj, s, lastSeen, newParent);

        // Build the updated tree using newParent
        vector<vector<int>> newAdj(n);
        for (int i = 1; i < n; ++i) {
            newAdj[newParent[i]].push_back(i);
        }

        // Pass 2: Calculate subtree sizes of the modified tree
        vector<int> ans(n, 0);
        computeSizes(0, newAdj, ans);

        return ans;
    }

private:
    void findNewParents(int u, const vector<vector<int>>& adj, const string& s,
                        vector<int>& lastSeen, vector<int>& newParent) {
        int charIdx = s[u] - 'a';
        int prevAncestor = lastSeen[charIdx];

        // If an ancestor with the same character exists, update parent
        if (prevAncestor != -1) {
            newParent[u] = prevAncestor;
        }

        // Set current node as the most recent ancestor for this character
        lastSeen[charIdx] = u;

        for (int v : adj[u]) {
            findNewParents(v, adj, s, lastSeen, newParent);
        }

        // Backtrack: restore previous state before leaving this branch
        lastSeen[charIdx] = prevAncestor;
    }

    int computeSizes(int u, const vector<vector<int>>& newAdj, vector<int>& ans) {
        int size = 1;
        for (int v : newAdj[u]) {
            size += computeSizes(v, newAdj, ans);
        }
        return ans[u] = size;
    }
};