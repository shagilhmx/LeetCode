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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL) return NULL;
        
        ListNode *curr = head;
        ListNode *prev = nullptr;
        
        while(left > 1){
            prev = curr;
            curr = curr -> next;
            left--;
            right--;
        }
        
        ListNode *connection = prev;
        ListNode *tail = curr;
        
        while(right > 0){
            ListNode *next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
            right--;
        }
        
        if(connection != NULL) connection->next = prev;
        else head = prev;
        
        tail->next = curr;
        
        return head;
    }
};