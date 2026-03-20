class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        Node* current = root;

        while (current->left != NULL) {
            Node* temp = current;

            while (temp != NULL) {
             
                temp->left->next = temp->right;

                if (temp->next != NULL) {
                    temp->right->next = temp->next->left;
                }

                temp = temp->next;
            }

            current = current->left;
        }

        return root;
    }
};