class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        
        // count[0] tracks even prefix sums (initialized to 1 for empty prefix sum 0)
        // count[1] tracks odd prefix sums
        int count[2] = {1, 0}; 
        int result = 0;
        int prefixSum = 0;
        
        for (int num : arr) {
            prefixSum += num;
            int currentParity = prefixSum & 1;
            
            // To get an odd subarray sum, we need a previous prefix sum of the opposite parity
            result = (result + count[currentParity ^ 1]) % MOD;
            
            // Record the current prefix sum's parity
            count[currentParity]++;
        }
        
        return result;
    }
};