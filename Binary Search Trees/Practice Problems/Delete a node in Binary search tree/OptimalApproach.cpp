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

    // Increase distance between levels.
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
TreeNode* deleteNodeInBst(TreeNode* node){
    if(node->left == NULL) return node->right;
    else if(node->right == NULL) return node->left;
    else {
        TreeNode* leftRoot = node->left;
        TreeNode* curr = node->right;
        while (curr->left){
            curr = curr->left;
        }
        curr->left = leftRoot;
        return node->right;
    }
}
TreeNode* deleteNode(TreeNode* root, int k) {
    if(!root) return root;
    if(root->val == k) return deleteNodeInBst(root);

    TreeNode* curr = root;
    while (curr){
        if(curr->val < k) {
            if(curr->right && curr->right->val == k){
                curr->right = deleteNodeInBst(curr->right);
                break;
            } 
            curr = curr->right;
        }

        else if(curr->val > k) {
            if(curr->left && curr->left->val == k){
                curr->left = deleteNodeInBst(curr->left);
                break;
            } 
            curr = curr->left;
        }
    }
    
    return root;
}
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

    cout << "BST Before Deletion:\n";
    printTree(root);

    int key = 3;

    root = deleteNode(root, key);

    cout << "\n\nBST After Deleting " << key << ":\n";
    printTree(root);

    return 0;
}
