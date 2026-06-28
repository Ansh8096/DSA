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
int InorderSuccessor_OP(TreeNode* root, TreeNode* x){
    TreeNode* curr = root;
    int ans = INT_MAX;
    while (curr)
    {
        if(curr->val <= x->val) curr = curr->right;
        else{
            ans = min(ans,curr->val);
            curr = curr->left; 
        }
    }
        
    return (ans == INT_MAX) ? -1 : ans;
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

    cout << "Binary Search Tree:\n";
    printTree(root);

    // Find inorder successor of node 6
    TreeNode* x = root->left->right;   // Node with value 6

    int successor = InorderSuccessor_OP(root, x);

    cout << "\n\nNode: " << x->val << endl;

    if(successor != -1)
        cout << "Inorder Successor: " << successor << endl;
    else
        cout << "Inorder Successor does not exist.\n";

    return 0;
}
