class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);  // Create a dummy node to handle the case of removing the head node
        dummy->next = head;
        ListNode* temp = dummy;

        while (temp->next != nullptr) {
            if (temp->next->val == val) {
                ListNode* toDelete = temp->next;
                temp->next = toDelete->next;
                delete toDelete;
            } else {
                temp = temp->next;
            }
        }

        head = dummy->next;  // Update the head pointer
        delete dummy;  // Free the memory allocated for the dummy node
        return head;
    }
};
