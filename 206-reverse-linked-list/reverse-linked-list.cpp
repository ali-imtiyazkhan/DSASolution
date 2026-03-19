class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;

        while(head){
          ListNode* Next = head->next;
          head->next = prev;
          prev = head;
          head = Next;
        }

        return prev;

    }
};

