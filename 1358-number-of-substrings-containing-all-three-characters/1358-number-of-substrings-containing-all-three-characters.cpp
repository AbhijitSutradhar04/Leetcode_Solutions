#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count = 0;
        int left = 0;
        vector<int> freq(3, 0); // Stores counts of 'a', 'b', 'c'

        for (int right = 0; right < n; ++right) {
            // Add current character to the window
            freq[s[right] - 'a']++;

            // Shrink the window from the left while it remains valid
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // Every substring starting at 'left' and ending at 'right' or later is valid
                count += (n - right);

                // Remove leftmost character and advance left pointer
                freq[s[left] - 'a']--;
                left++;
            }
        }

        return count;
    }
};