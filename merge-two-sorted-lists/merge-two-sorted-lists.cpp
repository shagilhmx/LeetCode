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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        struct ListNode* temp;
        temp = l2;
        
        if(l1!=NULL && l2!=NULL){
            while(temp->next != NULL){
                temp = temp -> next;
            }
            temp->next = l1;

            struct ListNode* head = l2;
            int temp1;
            while(head != NULL){
                struct ListNode* index = head->next;

                while(index != NULL){
                    if(head->val > index->val){
                        temp1 = head->val;
                        head->val = index->val;
                        index->val = temp1;
                    }
                    index = index->next;
                }
                head = head->next;
            }
            return l2;
        }
        else
        {
            if(l1 != NULL)
                return l1;
            else
                return l2;
        }
    }
};