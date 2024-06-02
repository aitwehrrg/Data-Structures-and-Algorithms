#include <bits/stdc++.h>
using namespace std;

template <typename T> void preOrderTraversal(vector<T>& tree, unsigned int index = 0) {
    cout << tree[index] << " ";
    if (index * 2 + 1 < tree.size()) preOrderTraversal(tree, index * 2 + 1);
    if (index * 2 + 2 < tree.size()) preOrderTraversal(tree, index * 2 + 2);
}

template <typename T> void inOrderTraversal(vector<T>& tree, unsigned int index = 0) {
    if (index * 2 + 1 < tree.size()) inOrderTraversal(tree, index * 2 + 1);
    cout << tree[index] << " ";
    if (index * 2 + 2 < tree.size()) inOrderTraversal(tree, index * 2 + 2);    
}

template <typename T> void postOrderTraversal(vector<T>& tree, unsigned int index = 0) {
    if (index * 2 + 1 < tree.size()) postOrderTraversal(tree, index * 2 + 1);
    if (index * 2 + 2 < tree.size()) postOrderTraversal(tree, index * 2 + 2);
    cout << tree[index] << " ";    
}