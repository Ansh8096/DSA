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
TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
    if(node == NULL|| node == p || node == q) return node;

    TreeNode* l = lowestCommonAncestor(node->left,p,q);
    TreeNode* r = lowestCommonAncestor(node->right,p,q);

    if(!r) return l;
    else if(!l) return r;
    else if(l && r) return node;
    else return NULL;
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
    TreeNode* p = new TreeNode(4);
    TreeNode* q = new TreeNode(5);
    root->left->left = p;
    root->left->right = q;

    TreeNode* ans = lowestCommonAncestor(root,p,q);

    cout<<ans->val;
    
    return 0;
}
