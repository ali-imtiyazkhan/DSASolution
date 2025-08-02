class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);  // New sorted list dummy head
        ListNode* curr = head;

        while (curr) {
            ListNode* prev = dummy;
            // Find correct insertion position
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            ListNode* nextTemp = curr->next;  // Save next node
            // Insert current between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;
            curr = nextTemp;
        }

        return dummy->next;
    }
};
