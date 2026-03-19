class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int count = 1;
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
            count++;
        }

        temp->next = head;

        k = k % count;
        int steps = count - k;

        ListNode* newTail = head;
        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};