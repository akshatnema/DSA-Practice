// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
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
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    int mx=-1;
    /*You are required to complete this method*/
    bool DFS(Node* root, int height){
        if(root==NULL){
            if(mx==-1){
                mx=height;
                return true;
            }else if(height==mx) return true;
            else return false;
        }
        height++;
        if(!root->left && !root->right){
            if(mx==-1){
                height=mx;
                return true;
            }else if(height==mx) return true;
            else return false;
        }else{
            bool temp=true;
            if(root->left){
                temp = temp & DFS(root->left, height);
            }
            if(root->right)
                temp = temp & DFS(root->right, height);
        
            return temp;
        }
    }
    bool check(Node *root)
    {
        vector<pair<int,int>> v;
        queue<Node*> q;
        int flag=0;
        q.push(root);
        while(!q.empty()){
            queue<Node*> temp;
            while(q.size()){
                Node* front = q.front();
                if(flag==1 && (front->left || front->right)) return false;
                if(flag==2 && (!front->left && !front->right)) return false;
                if(flag==0 && (front->left || front->right)) flag=2;
                if(flag==0 && (!front->left && !front->right)) flag=1;
                if(front->left) temp.push(front->left);
                if(front->right) temp.push(front->right);
                q.pop();
            }
            q=temp;
            flag=0;
        }
        return true;
    }
};

// { Driver Code Starts.
// Driver program to test size function
int main()
{
    int t;
    cin>> t;
    getchar();
    while (t--)
    {
        string s;
        getline( cin, s );
        Node* head = buildTree( s );
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}
  // } Driver Code Ends