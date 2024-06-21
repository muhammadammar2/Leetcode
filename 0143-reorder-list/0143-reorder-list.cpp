/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        //first get to the mid
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //reverse the list
        ListNode* current = slow->next;
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        
        while (current != NULL) {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        slow->next = NULL; //cutting the 2 halfs
        
        //merge the 2 lists (halfs)
        ListNode* first = head;
        ListNode* second = prev;
        
        while (first!=NULL && second!=NULL) {
         ListNode* temp1 = first->next;
         ListNode* temp2 = second->next;
            
            first->next = second;
            second->next = temp1;
            
         first = temp1;
         second = temp2;
        }
        
    }
};