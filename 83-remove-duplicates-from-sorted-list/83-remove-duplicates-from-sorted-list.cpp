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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *slow = head, *fast = slow -> next;
        
        while(fast != NULL) {
            if(slow -> val == fast -> val) {
                //remove
                slow -> next = fast -> next;
                fast = fast -> next;
            }
            else {
                slow = slow -> next;
                fast = slow -> next;
            }
        }
        return head;
    }
};

/* [1] -> [1] -> [2] */