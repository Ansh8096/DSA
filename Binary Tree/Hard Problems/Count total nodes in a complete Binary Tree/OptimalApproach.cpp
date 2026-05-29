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
int leftHeight(TreeNode* node){
    int cnt = 1;
    while (node->left)
    {
        cnt++;
        node = node->left; 
    }
    return cnt;
}
int rightHeight(TreeNode* node){
    int cnt = 1;
    while (node->right)
    {
        cnt++;
        node = node->right; 
    }
    return cnt;
}
void traverseBinaryTree(TreeNode* node, int& cnt){
    if(!node) return;
    int lh = leftHeight(node);
    int rh = rightHeight(node);
    if(lh != rh) cnt += 1;
    else {
        cnt += (1<<lh) - 1;
        return;
    }
    
    traverseBinaryTree(node->left,cnt);
    traverseBinaryTree(node->right,cnt);
}
int countTotalNodesInBinaryTree_OP(TreeNode* root){
    int cnt = 0;
    traverseBinaryTree(root,cnt);
    return cnt;                          
}
int main(){

    // Constructing tree:-
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);;
    root->left->right = new TreeNode(5);

    cout<<countTotalNodesInBinaryTree_OP(root);

    return 0;
}
