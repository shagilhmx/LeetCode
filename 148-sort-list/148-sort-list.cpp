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
    ListNode* merge(ListNode *A, ListNode *B) {
        if(!A) return B;
        if(!B) return A;
        
        if(A -> val > B -> val) {
            B -> next = merge(A, B -> next);
            return B;
        }
        else {
            A -> next = merge(A -> next, B);
            return A;
        }
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *fast, *slow, *temp;
        slow = fast = head;
        
        while(fast && fast -> next) {
            temp = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        temp -> next = nullptr;
        
        ListNode *A = sortList(head);
        ListNode *B = sortList(slow);
        
        return merge(A, B);
    }
};