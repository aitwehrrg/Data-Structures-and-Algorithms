#include <bits/stdc++.h>
using namespace std;

template <typename T> struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode<T>(T data = T{}, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr): data(data), left(left), right(right) {}
};

template <typename T> void preOrderTraversal(TreeNode<T>* root) {
    if (root == nullptr) return;
    cout << root -> data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

template <typename T> void inOrderTraversal(TreeNode<T>* root) {
    if (root == nullptr) return;
    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
}

template <typename T> void postOrderTraversal(TreeNode<T>* root) {
    if (root == nullptr) return;
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root -> data << " ";
}