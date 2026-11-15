class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // Count stones by their value modulo 3 (remainders 0, 1, and 2)
        int count[3] = {0, 0, 0};
        for (int stone : stones) {
            count[stone % 3]++;
        }
        
        // Case 1: Even number of remainder-0 stones
        // Alice wins if both remainder-1 and remainder-2 stones exist
        if (count[0] % 2 == 0) {
            return count[1] >= 1 && count[2] >= 1;
        }
        
        // Case 2: Odd number of remainder-0 stones
        // Alice wins if one remainder type outnumbers the other by more than 2
        return abs(count[1] - count[2]) > 2;
    }
};