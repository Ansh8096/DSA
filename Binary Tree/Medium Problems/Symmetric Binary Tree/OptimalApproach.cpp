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
bool traverseAndCheck(TreeNode* node1, TreeNode* node2){
    if(node1 == NULL && node2 == NULL) return true;
    if(node1 == NULL || node2 == NULL) return false;

    return (node1->val == node2->val && traverseAndCheck(node1->right,node2->left) && traverseAndCheck(node1->left,node2->right));
}
bool isSymmetric(TreeNode* root) {
    return traverseAndCheck(root->left,root->right);
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

    cout<<isSymmetric(root);

    return 0;
}
