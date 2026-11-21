using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        unordered_set<int> seen;

        // Find the range boundaries and record all present numbers
        for (int num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
            seen.insert(num);
        }

        // Collect all integers in (mn, mx) that are missing from the set
        vector<int> ans;
        for (int x = mn + 1; x < mx; ++x) {
            if (!seen.count(x)) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};