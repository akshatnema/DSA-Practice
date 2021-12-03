// Question link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
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
class Solution
{
public:
    void preorder(TreeNode *root, vector<int> &v, int &k)
    {
        if (root == NULL)
            return;

        preorder(root->left, v, k);
        if (v.size() == k)
            return;
        v.push_back(root->val);
        if (v.size() == k)
            return;
        preorder(root->right, v, k);

        return;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> v;
        preorder(root, v, k);
        return v[k - 1];
    }
};