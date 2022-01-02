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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) return nullptr;
        
        ListNode *lessNode = new ListNode(0);
        ListNode *greaterNode = new ListNode(0);
        ListNode *less_temp = lessNode;
        ListNode *greater_temp = greaterNode;
        
        while(head){
            if(x > head -> val) {
                ListNode *newNode = new ListNode(head->val);
                less_temp -> next = newNode;
                less_temp = less_temp -> next;
            }
            else {
                ListNode *newNode = new ListNode(head->val);
                greater_temp -> next = newNode;
                greater_temp = greater_temp -> next;
            }
            head = head -> next;
        }
        less_temp -> next = greaterNode->next;
        return lessNode -> next;
    }
};