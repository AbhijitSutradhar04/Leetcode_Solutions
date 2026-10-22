#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Step 1: Pair each element with its original index
        vector<pair<int, int>> sortedNums(n);
        for (int i = 0; i < n; ++i) {
            sortedNums[i] = {nums[i], i};
        }
        
        // Step 2: Sort pairs by value
        sort(sortedNums.begin(), sortedNums.end());
        
        vector<int> ans(n);
        int i = 0;
        
        // Step 3: Group elements and assign values back to original indices
        while (i < n) {
            int j = i;
            vector<int> indices;
            vector<int> values;
            
            indices.push_back(sortedNums[i].second);
            values.push_back(sortedNums[i].first);
            
            // Find all elements that can be connected (difference <= limit)
            while (j + 1 < n && sortedNums[j + 1].first - sortedNums[j].first <= limit) {
                j++;
                indices.push_back(sortedNums[j].second);
                values.push_back(sortedNums[j].first);
            }
            
            // Sort original indices so smaller values go to smaller index positions
            sort(indices.begin(), indices.end());
            
            // Assign sorted values back to the corresponding sorted indices
            for (int k = 0; k < indices.size(); ++k) {
                ans[indices[k]] = values[k];
            }
            
            i = j + 1;
        }
        
        return ans;
    }
};
