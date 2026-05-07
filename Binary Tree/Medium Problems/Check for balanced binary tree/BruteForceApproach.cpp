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
int maxDepthOFTree(TreeNode* node) {
    if(node == NULL) return 0;
    int l = maxDepthOFTree(node->left);
    int r = maxDepthOFTree(node->right);
    return (1 + max(l,r));
}
bool isTreeBalanced_BR(TreeNode* node) {
    if(node == NULL) return true;
    int leftHeight = maxDepthOFTree(node->left);
    int rightHeight = maxDepthOFTree(node->right);
    if(abs(leftHeight-rightHeight) > 1) return false;

    bool left = isTreeBalanced_BR(node->left);
    bool right = isTreeBalanced_BR(node->right);
    if(!left || !right) return false;
    else return true;
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

    cout<<isTreeBalanced_BR(root);

    return 0;
}
