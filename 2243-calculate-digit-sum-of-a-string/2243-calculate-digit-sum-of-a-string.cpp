using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        // Continue rounds until the string length is at most k
        while (s.length() > k) {
            string nextString = "";
            int n = s.length();
            
            // Iterate through the string in steps of k
            for (int i = 0; i < n; i += k) {
                int groupSum = 0;
                
                // Sum the digits in the current group of size up to k
                for (int j = i; j < min(i + k, n); ++j) {
                    groupSum += s[j] - '0';
                }
                
                // Append the group sum as a string to the next round's string
                nextString += to_string(groupSum);
            }
            
            // Replace s with the newly formed string
            s = nextString;
        }
        
        return s;
    }
};