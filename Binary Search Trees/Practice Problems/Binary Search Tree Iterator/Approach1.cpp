#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val1){
        val = val1;
        left = NULL;
        right = NULL;
    }
};
void printTree(TreeNode* root, int space = 0, int gap = 5){

    if(root == NULL) return;

    // Increase distance between levels
    space += gap;

    // Print right subtree first
    printTree(root->right, space);

    // Print current node
    cout << endl;

    for(int i = gap; i < space; i++){
        cout << " ";
    }

    cout << root->val << "\n";

    // Print left subtree
    printTree(root->left, space);
}
class BSTIterator {
    private:
    stack<TreeNode*> stk;
    void pushAll(TreeNode* node){
        for(; node != NULL; stk.push(node), node=node->left);
    }

    public:
    BSTIterator(TreeNode* root) {
        pushAll(root);  
    }
    
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        if(node->right) pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};
int main(){

    // Constructing BST:
    //
    //          8
    //        /   \
    //       3     10
    //      / \      \
    //     1   6      14
    //        / \     /
    //       4   7   13

    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    cout << "Binary Search Tree:\n";
    printTree(root);

    BSTIterator it(root);

    cout << "\n\nBST Iterator (Inorder Traversal): ";

    while (it.hasNext()) {
        cout << it.next() << " ";
    }

    cout << endl;

    return 0;
}
