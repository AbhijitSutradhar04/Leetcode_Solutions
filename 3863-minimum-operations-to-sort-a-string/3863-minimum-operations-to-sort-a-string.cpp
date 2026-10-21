#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.size();

        // Case 1: The string is already sorted.
        if (std::is_sorted(s.begin(), s.end())) {
            return 0;
        }

        if (n == 2) {
            return -1;
        }

        int min_idx = 0;
        int max_idx = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] < s[min_idx]) {
                min_idx = i;
            }
            if (s[i] >= s[max_idx]) {
                max_idx = i;
            }
        }
        if (min_idx == 0 || max_idx == n - 1) {
            return 1;
        }

        if (min_idx == n - 1 && max_idx == 0) {
            return 3;
        }
        return 2;
    }
};
