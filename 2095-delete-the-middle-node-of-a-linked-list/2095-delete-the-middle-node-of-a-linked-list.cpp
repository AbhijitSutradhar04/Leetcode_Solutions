class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head->next->next; // Start fast 2 steps ahead

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow->next is guaranteed to be the middle node
        ListNode* middle = slow->next;
        slow->next = slow->next->next;
        delete middle;

        return head;
    }
};
