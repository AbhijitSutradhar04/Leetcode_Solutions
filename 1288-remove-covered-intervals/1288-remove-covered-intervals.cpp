#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Sort: Ascending by start point. If starts are equal, descending by end point.
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        int remainingCount = 0;
        int maxEnd = 0;
        
        for (const auto& interval : intervals) {
            // If the current interval's end extends beyond the maximum end seen so far,
            // it cannot be fully covered by any previous interval.
            if (interval[1] > maxEnd) {
                remainingCount++;
                maxEnd = interval[1]; // Update the boundary
            }
            // If interval[1] <= maxEnd, it is completely covered by a previous interval, so we skip it.
        }
        
        return remainingCount;
    }
};
