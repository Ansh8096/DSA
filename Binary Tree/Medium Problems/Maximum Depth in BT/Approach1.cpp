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

    cout<<maxDepthOFTree(root);

    return 0;
}
