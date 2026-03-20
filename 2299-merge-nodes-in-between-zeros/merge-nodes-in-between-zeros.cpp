class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modify = head;   
        ListNode* temp = head->next; 
        int sum = 0;

        while (temp != nullptr) {
            if (temp->val == 0) {
               
                modify->val = sum;
                modify->next = temp->next; 
                modify = modify->next;

                sum = 0;
            } else {
                sum += temp->val;
            }
            temp = temp->next;
        }

        return head;
    }
};