class Solution {
public:
    bool canAliceWin(int n) {
        int stonesToRemove = 10;
        int turns = 0;
        
        while (n >= stonesToRemove) {
            n -= stonesToRemove;
            --stonesToRemove;
            ++turns;
        }
        
        // Alice wins if an odd number of total turns were completed
        return turns % 2 == 1;
    }
};