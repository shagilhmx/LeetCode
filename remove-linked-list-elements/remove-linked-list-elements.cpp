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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        
        while(head) {
            if(head->val != val) {
                ListNode *new_node = new ListNode(head->val);
                temp -> next = new_node;
                temp = temp -> next;
            }
            head = head -> next;
        }
        return dummy->next;
    }
};