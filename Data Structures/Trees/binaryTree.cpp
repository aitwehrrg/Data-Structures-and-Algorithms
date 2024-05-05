#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data = 0, TreeNode* left = nullptr, TreeNode* right = nullptr): data(data), left(left), right(right) {}
};

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    cout << root -> data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root -> data << " ";
}