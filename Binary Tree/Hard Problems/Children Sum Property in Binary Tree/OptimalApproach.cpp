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
void childrenSumPropertyOfTree(TreeNode* node){
    if(node == NULL) return;
    
    int val1 = (node->left) ? node->left->val : 0;
    int val2 = (node->right) ? node->right->val : 0;
    if(node->val > val1+val2){
        if(node->left) node->left->val = node->val;
        if(node->right) node->right->val = node->val;
    }
    else{
        node->val = val1+val2;
    }

    childrenSumPropertyOfTree(node->left);
    childrenSumPropertyOfTree(node->right);

    int x1 = (node->left) ? node->left->val : 0;
    int x2 = (node->right) ? node->right->val : 0;
    if(x1 || x2) node->val = x1+x2;
}
int main(){

    // Constructing tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Tree before applying Children Sum Property:\n";
    printTree(root); // Function to print tree like structure

    childrenSumPropertyOfTree(root);

    cout << "\n\nTree after applying Children Sum Property:\n";
    printTree(root); // Function to print tree like structure

    return 0;
}
