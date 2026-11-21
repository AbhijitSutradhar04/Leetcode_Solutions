class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCritical = -1, prevCritical = -1, minDistance = INT_MAX;
        ListNode *prev = head, *curr = head->next;
        int index = 1;

        while (curr != nullptr && curr->next != nullptr) {
            bool isLocalMax = (curr->val > prev->val && curr->val > curr->next->val);
            bool isLocalMin = (curr->val < prev->val && curr->val < curr->next->val);

            if (isLocalMax || isLocalMin) {
                if (firstCritical == -1) firstCritical = index;
                else minDistance = min(minDistance, index - prevCritical);
                prevCritical = index;
            }
            prev = curr;
            curr = curr->next;
            ++index;
        }

        if (minDistance == INT_MAX) return {-1, -1};
        return {minDistance, prevCritical - firstCritical};
    }
};