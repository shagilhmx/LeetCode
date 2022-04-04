// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method
struct Node* reverse(struct Node* curr)
{
    struct Node *prev = NULL , *next;
    
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* getbigger(struct Node*l1 , struct Node * l2)
{
    struct Node* head1 = l1 , *head2 = l2;
    
    while(l1 && l2)
    {
        if(l1->data > l2->data)
        return head1;
        else if(l1->data < l2->data)
        return head2;
        
        l1 = l1->next;
        l2 = l2->next;
    }
    return head1;
}
Node* subLinkedList(Node* l1, Node* l2)
{
    //reverse the list
    if( l1== NULL && l2==NULL)
    return NULL;
    //Your code here
    int count1 = 0 , count2 = 0 , diff ;
    
    struct Node *result = NULL , *tail , *node1 = l1 , *node2 = l2, *prev;
    
    bool borrow = false;
    
    //preciding zero conditions.......
    
    while(node1->data == 0 && node1->next!=NULL)
    node1 = node1->next;
    
    while(node1!= NULL)
    {
        count1++;
       node1 = node1->next;
    }
    
    //preciding zero conditions.......
    
    while(node2->data == 0 && node2->next!=NULL)
    node2 = node2->next;
    
    while(node2!=NULL)
    {
        count2++;
        node2 = node2->next;
    }
    
    if(count1 > count2)
    {
        node1 = l1;
        node2 = l2;
    }
    else if (count2 > count1)
    {
        node1 = l2;
        node2 = l1;
    }
    else
    {
        node1 = getbigger(l1 , l2);
        node2 = node1 == l1 ? l2:l1 ;
    }
    
    
    node1 = reverse(node1);
    node2 = reverse(node2);
    
    while(node1 || node2)
    {
        if(borrow)
        {
            if(node1->data!=0)
            {
            node1->data = node1->data - 1;
            borrow = false;
            }
            // if data is  zero borrow continues.......
            else
            {
                node1->data = 9;
                borrow = true;
            }
        }
        
        if(node1!=NULL && node2!=NULL && node1->data < node2->data)
        {
            node1->data = node1->data + 10;
            borrow = true;
        }
        
        diff = (node1 ? node1->data : 0) - (node2 ? node2->data : 0);
        
       
        if(result == NULL)
        {
           
            result = tail =  new Node(abs(diff));
        }
        else
        {
            tail->next = new Node(abs(diff));
            prev = tail;
            tail = tail->next;
        }
        
        
        if(node1)
        node1 =node1->next;
        
        if(node2)
        node2 = node2->next;
        
        
    }
    
    result = reverse(result);
    
    // to remove preciding zero.....
    while(result->data == 0 && result->next!=NULL)
    {
        result = result->next;
    }
    
    return result;
}