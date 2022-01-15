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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        
        if(!head || k == 1) return head;
        
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *curr = dummy;
        
        while(curr -> next) {
            curr = curr -> next;
            count++;
        }
        
        ListNode *pre = dummy, *next_ = dummy;
        
        while(count >= k) {
            curr = pre -> next;
            next_ = curr -> next;
            
            for(int i=1;i<k;i++) {
                curr -> next = next_ -> next;
                next_ -> next = pre -> next;
                pre -> next = next_;
                next_ = curr -> next;
            }
            pre = curr;
            count -= k;
        }
        return dummy -> next;
    }
};