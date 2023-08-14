 /* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//https://leetcode.com/contest/weekly-contest-358/problems/double-a-number-represented-as-a-linked-list/
class Solution {
public:
    
    //https://www.geeksforgeeks.org/reverse-a-linked-list/ -  See visualization
    ListNode* reverseList(head){
        ListNode* current = head;
        ListNode* prev,next = nullptr;
        while(currentNode != nullptr){
        
            next = current->next;  //update next to increament becasue later we give to current
            current->next = prev;  // link ne reverse kari 
            
            //ahead
            prev = current;
            current = next;
        }
        return prev;
    }
    
    ListNode* doubleList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = head;
        
        int carry=0,sum=0;
        while(temp != null){
            
            //Calculation of {Sum-Carry}
            sum = carry + (temp->val)*2;
            carry = sum/10;
            sum = sum % 10;
            
            temp->val = sum;
            prev = temp;
            temp = temp->next;
        }
        
        if(carry > 0) prev->next = new ListNode(carry);
        
        return head;
    }
    
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        head = doubleList(head);
        return reverseList(head);
    }
};