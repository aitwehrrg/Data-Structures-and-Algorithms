#include <bits/stdc++.h>
using namespace std;

template <typename T> struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T data = T{}, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr): data(data), left(left), right(right) {}
};

template <typename T> void preorderTraversal(TreeNode<T>* root) {
    if (root == nullptr) return;
    cout << root -> data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

template <typename T> void inorderTraversal(TreeNode<T>* root) {
    if (root == nullptr) return;
    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

template <typename T> void postorderTraversal(TreeNode<T>* root) {
    if (root == nullptr) return;
    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    cout << root -> data << " ";
}