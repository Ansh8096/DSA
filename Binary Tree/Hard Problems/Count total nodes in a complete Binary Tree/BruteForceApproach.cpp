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
void traverseAndCountNodes(TreeNode* node, int &cnt){
    if(node == NULL){
        return;
    }
    cnt++;
    traverseAndCountNodes(node->left, cnt);
    traverseAndCountNodes(node->right, cnt);
}
int countTotalNodesInBinaryTree_BR(TreeNode* root){
    int cnt = 0;
    traverseAndCountNodes(root,cnt);
    return cnt;
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
    root->left->left = new TreeNode(4);;
    root->left->right = new TreeNode(5);

    cout<<countTotalNodesInBinaryTree_BR(root);

    return 0;
}
