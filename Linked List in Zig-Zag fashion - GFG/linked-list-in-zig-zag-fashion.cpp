// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *root)
{
	Node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
 

 // } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

class Solution
{
    public:
    void swap(Node *a, Node *b) {
        int temp = a -> data;
        a -> data = b -> data;
        b -> data = temp;
    }
    
    public:
    Node *zigZag(Node* head)
    {
        if(!head || !head -> next) return head;
        
        bool even = false;
        Node *curr = head;
        
        while(curr -> next) {
            if(even) {
                if(curr -> data < curr -> next -> data) swap(curr, curr->next);
                even = false;
            }
            else {
                if(curr -> data > curr -> next -> data) swap(curr, curr->next);
                even = true;
            }
            curr = curr -> next;
        }
        return head;
    }
};

// { Driver Code Starts.


int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Solution ob;
		Node *ans = ob.zigZag(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends