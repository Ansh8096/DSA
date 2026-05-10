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
bool isSameTree(TreeNode* node1, TreeNode* node2) {
    if (node1 == NULL || node2 == NULL)
        return node1 == node2;
    return ((node1->val == node2->val) &&
            (isSameTree(node1->left, node2->left)) &&
            (isSameTree(node1->right, node2->right)));
}
int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    cout<<isSameTree(root,root1);

    return 0;
}
