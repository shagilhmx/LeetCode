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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        unordered_map <int, ListNode*> umap;
        umap[0] = dummy;
        int preSum = 0;
        
        while(head) {
            preSum += head -> val;
            umap[preSum] = head;
            head = head -> next;
        }
        
        head = dummy;
        preSum = 0;
        while(head) {
            preSum += head -> val;
            ListNode *temp = umap[preSum];
            if(temp != head)
                head -> next = temp -> next;
            head = head -> next;
        }
        return dummy->next;
    }
};