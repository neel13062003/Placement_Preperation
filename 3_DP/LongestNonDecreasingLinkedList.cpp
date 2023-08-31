#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

int findLNIS(ListNode* head) {
    if (!head) {
        return 0;
    }
    
    ListNode* longestEnd = head;
    ListNode* curr = head;
    
    while (curr) {
        ListNode* prev = curr;
        int length = 1;
        
        while (prev->next && prev->next->val <= prev->val) {
            length++;
            prev = prev->next;
        }
        
        if (length > 1 && length > (longestEnd - curr + 1)) {
            longestEnd = prev;
        }
        
        curr = curr->next;
    }
    
    // Count the nodes in the LNIS
    int count = 0;
    ListNode* temp = longestEnd->next;
    while (temp != nullptr) {
        temp = temp->next;
        count++;
    }
    
    return count + 1; // +1 to include the longestEnd node
}

int main() {
    // Create the linked list: 1->3->1->5->4->4->6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(6);

    int lnisCount = findLNIS(head);

    cout << "Length of Longest Non-Increasing Subsequence: " << lnisCount << endl;

    return 0;
}
