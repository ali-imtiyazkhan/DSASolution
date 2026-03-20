class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
       ListNode* temp = head->next;
       ListNode* dummy = new ListNode(0);
       ListNode* curr = dummy;

       int sum = 0;

       while(temp != nullptr){
        if(temp->val == 0){
            curr->next = new ListNode(sum);
            curr = curr->next;
            sum = 0;
        }
        else{
            sum += temp->val;
        }

        temp = temp->next;
       } 

       return dummy->next;
    }
};