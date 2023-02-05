/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        vector<Node* > q;
        q.push_back(root);
        while(q.size()){
            vector<Node* > temp =q;
            q.clear();
            for(int i=0;i<temp.size();i++){
                if(temp[i]->left!=NULL)
                 q.push_back(temp[i]->left);
                if(temp[i]->right!=NULL)
                 q.push_back(temp[i]->right);
                if(i+1<temp.size())
                 temp[i]->next=temp[i+1];
            }
            temp[temp.size()-1]->next=NULL;
        }
        return root;
    }
};