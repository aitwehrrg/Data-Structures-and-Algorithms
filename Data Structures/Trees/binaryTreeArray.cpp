#include <bits/stdc++.h>
using namespace std;

template <typename T> void preorderTraversal(vector<T>& tree, unsigned int index = 0) {
    if (index >= tree.size()) return;
    cout << tree[index] << " ";
    preorderTraversal(tree, index * 2 + 1);
    preorderTraversal(tree, index * 2 + 2);
}

template <typename T> void inorderTraversal(vector<T>& tree, unsigned int index = 0) {
    if (index >= tree.size()) return;
    inorderTraversal(tree, index * 2 + 1);
    cout << tree[index] << " ";
    inorderTraversal(tree, index * 2 + 2);    
}

template <typename T> void postorderTraversal(vector<T>& tree, unsigned int index = 0) {
    if (index >= tree.size()) return;
    postorderTraversal(tree, index * 2 + 1);
    postorderTraversal(tree, index * 2 + 2);
    cout << tree[index] << " ";    
}