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

    // Increase distance between levels..
    space += gap;

    // Print right subtree first...
    printTree(root->right, space);

    // Print current node...
    cout << endl;

    for(int i = gap; i < space; i++){
        cout << " ";
    }

    cout << root->val << "\n";

    // Print left subtree...
    printTree(root->left, space);
}
TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* node = new TreeNode(val);
    if(!root) return node;
    TreeNode* curr = root;
    while (curr)
    {
        if(curr->val < val){
            if(curr->right == NULL){
                curr->right = node;
                break;
            }
            curr = curr->right;
        }
        
        else{
            if(curr->left == NULL){
                curr->left = node;
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

    cout << "BST Before Insertion:\n";
    printTree(root);

    int val = 5;

    root = insertIntoBST(root, val);

    cout << "\n\nBST After Inserting " << val << ":\n";
    printTree(root);

    return 0;
}
