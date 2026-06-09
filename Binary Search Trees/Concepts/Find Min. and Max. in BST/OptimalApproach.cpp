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
pair<TreeNode*, TreeNode*> findMaxAndMinInBST(TreeNode* root){
    TreeNode* mini = root;
    while (mini->left){
        mini = mini->left;
    }
    
    TreeNode* maxi = root;
    while (maxi->right){
        maxi = maxi->right;
    }

    return {mini,maxi};
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

    cout << "BST:\n";
    printTree(root);

    pair<TreeNode*, TreeNode*> result = findMaxAndMinInBST(root);

    cout << "\n\nMinimum Node Value: "
        << result.first->val;

    cout << "\nMaximum Node Value: "
        << result.second->val << endl;

    return 0;
}
