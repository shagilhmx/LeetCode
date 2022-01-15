/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        
        Node *ptr = head, *curr = nullptr, *store_ptr = nullptr;
        while(ptr) {
            if(ptr -> child) {
                store_ptr = ptr -> next;
                ptr -> next = ptr -> child;
                ptr -> next -> prev = ptr;
                ptr -> child = nullptr;
                
                curr = ptr -> next;
                while(curr -> next) curr = curr -> next;

                curr -> next = store_ptr;
                if(curr -> next) curr -> next -> prev = curr;
            }
            ptr = ptr -> next;
        }
        return head;
    }
};