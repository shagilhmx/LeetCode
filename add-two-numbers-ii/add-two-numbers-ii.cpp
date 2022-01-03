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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stackOne;
        stack<int> stackTwo;
        stack<int> ans;
        
        while(l1) {
            stackOne.push(l1->val);
            l1 = l1 -> next;
        }
        
        while(l2) {
            stackTwo.push(l2->val);
            l2 = l2 -> next;
        }
        
        int carry = 0;
        while(!stackOne.empty() || !stackTwo.empty() || carry != 0) {
            int sum = 0;
            if(!stackOne.empty()) {
                sum += stackOne.top();
                stackOne.pop();
            }
            if(!stackTwo.empty()) {
                sum += stackTwo.top();
                stackTwo.pop();
            }
            
            sum += carry;
            carry = sum / 10;
            ans.push(sum % 10);
        }
        
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        while(!ans.empty()){
            ListNode *new_node = new ListNode(ans.top());
            temp -> next = new_node;
            temp = temp -> next;
            ans.pop();
        }
        return dummy -> next;
    }
};