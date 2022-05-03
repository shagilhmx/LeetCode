// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
  public:
    // function should return the number of turns required to go from first node to second node 
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      if(root == nullptr || first == second)
        return 0;
        
        Node *lc = lca(root, first, second);
        int res = 0;
        
        if(lc -> data != first && lc -> data != second)
            res++;
        
        path(lc, first, 0, res, "");
        path(lc, second, 0, res, "");
        
        if(res == 0)
            return -1;
        else
            return res;
    }
    
    Node* lca(Node* root, int first, int second) {
        if(!root || root -> data == first || root -> data == second)
            return root;
        Node* left = lca(root -> left, first, second);
        Node* right = lca(root -> right, first, second);
        
        if(!left)
            return right;
        else if(!right)
            return left;
        else 
            return root;
    }
    
    void path(Node* root, int elem, int turns, int& res, string str) {
        if(!root)
            return;
            
        if(root -> data == elem) {
            res += turns;
            return;
        }
        
        if(str == "") {
            path(root -> left, elem, turns, res, "left");
            path(root -> right, elem, turns, res, "right");
        }
        else {
            if(str == "left") {
                path(root -> left, elem, turns, res, "left");
                path(root -> right, elem, turns + 1, res, "right");
            }
            else {
                path(root -> left, elem, turns + 1, res, "left");
                path(root -> right, elem, turns, res, "right");
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}
  // } Driver Code Ends