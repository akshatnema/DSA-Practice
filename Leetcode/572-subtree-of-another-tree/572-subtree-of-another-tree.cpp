/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int flag=0;
    bool DFS(TreeNode* root, TreeNode* subRoot){
        if(root&&subRoot){
            if(root->val==subRoot->val)
            {
                return DFS(root->left, subRoot->left) && DFS(root->right, subRoot->right);
            }else return false;
        }
        if(root || subRoot) return false;
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root && DFS(root,subRoot)) return true;
        if(root&&subRoot){
            return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
        }
        return false;
    }
};