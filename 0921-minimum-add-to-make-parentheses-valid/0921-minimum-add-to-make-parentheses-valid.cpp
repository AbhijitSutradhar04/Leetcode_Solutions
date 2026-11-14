using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;  // Tracks unmatched '('
        int close = 0; // Tracks unmatched ')'

        for (char c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0) {
                    // Match this ')' with a previous unmatched '('
                    open--;
                } else {
                    // No '(' available to match, so we need an insertion
                    close++;
                }
            }
        }

        return open + close;
    }
};