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
int calculateSum(TreeNode* node) {
    if (node == NULL) return 0;
    int l = calculateSum(node->left);
    int r = calculateSum(node->right);
    // Ignoring the negative child node completely...
    int bestChild = max(l, r);
    if (bestChild < 0) bestChild = 0;
    return (node->val + bestChild);
}
void explorePaths(TreeNode* node, int& maxii) {
    if (node == NULL) return;
    int l = calculateSum(node->left);
    int r = calculateSum(node->right);
    // // Ignoring the negative child node completely...
    l = max(l, 0);
    r = max(r, 0);
    maxii = max(maxii, l + r + node->val);
    explorePaths(node->left, maxii);
    explorePaths(node->right, maxii);
}
int maxPathSum_BR(TreeNode* node) {
    int maxii = INT_MIN;
    explorePaths(node, maxii);
    return maxii;
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

    cout<<maxPathSum_BR(root);

    return 0;
}
