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
int isBalanced(TreeNode* node){
    if(node == NULL) return 0;

    int leftHeight = isBalanced(node->left);
    if(leftHeight == -1) return -1;

    int rightHeight = isBalanced(node->right);
    if(rightHeight == -1) return -1;

    if(abs(leftHeight - rightHeight) > 1)return -1;
    return (1 + max(leftHeight,rightHeight));
}
bool isTreeBalanced_OP(TreeNode* root) {
    return (isBalanced(root) != -1);
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

    cout<<isTreeBalanced_OP(root);

    return 0;
}
