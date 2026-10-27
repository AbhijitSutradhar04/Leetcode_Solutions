class Solution {
public:
    int maxScore(std::vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int current_score = 0;
        
        // Step 1: Get the initial sum of the first k cards from the left
        for (int i = 0; i < k; ++i) {
            current_score += cardPoints[i];
        }
        
        int max_score = current_score;
        
        // Step 2: Slide the window. 
        // Remove one card from the left (starting at index k-1) 
        // and add one card from the right (starting at index n-1)
        for (int i = 0; i < k; ++i) {
            current_score -= cardPoints[k - 1 - i]; // Drop from left
            current_score += cardPoints[n - 1 - i]; // Take from right
            max_score = std::max(max_score, current_score);
        }
        
        return max_score;
    }
};