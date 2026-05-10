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
int calculateMaxSum(TreeNode* node, int &maxii){
    if(node == NULL) return 0;
    int l = calculateMaxSum(node->left,maxii);
    int r = calculateMaxSum(node->right,maxii);

    l = max(l,0);
    r = max(r,0);

    maxii = max(maxii, l + r + node->val);

    return (node->val + max(l,r));
}
int maxPathSum_OP(TreeNode* node) {
    int maxii = 0;
    calculateMaxSum(node, maxii);
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

    cout<<maxPathSum_OP(root);

    return 0;
}
