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
TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* curr = root;
    while (curr && curr->val != val){
        curr = (curr->val>val) ? curr->left : curr->right;
    }

    return curr;
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

    int target = 6;

    TreeNode* result = searchBST(root, target);

    if(result){
        cout << "\n\nSubtree rooted at " << target << ":\n";
        printTree(result);
    }
    else{
        cout << "\n\nValue " << target << " not found.\n";
    }

    return 0;
}
