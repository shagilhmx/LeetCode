/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iterator, *front;
        iterator = head, front = head;
        
        while(iterator) {
            front = iterator -> next;
            Node *new_node = new Node(iterator -> val);
            iterator -> next = new_node;
            new_node -> next = front;
            iterator = front;
        }
        
        iterator = head;
        
        while(iterator) {
            if(iterator -> random != nullptr)
                iterator -> next -> random = iterator -> random -> next;
            iterator = iterator -> next -> next;
        }
        
        iterator = head;
        Node *dummy = new Node(0);
        Node *copy = dummy;
        
        while(iterator) {
            front = iterator -> next -> next;
            copy -> next = iterator -> next;
            iterator -> next = front;
            copy = copy -> next;
            iterator = iterator -> next;
        }
        
        return dummy -> next;
    }
};