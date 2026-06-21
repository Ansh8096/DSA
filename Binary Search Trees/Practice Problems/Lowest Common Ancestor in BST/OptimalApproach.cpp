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
void printTree(TreeNode* root, int space = 0, int gap = 5){

    if(root == NULL) return;

    // Increase distance between levels
    space += gap;

    // Print right subtree first
    printTree(root->right, space);

    // Print current node
    cout << endl;

    for(int i = gap; i < space; i++){
        cout << " ";
    }

    cout << root->val << "\n";

    // Print left subtree
    printTree(root->left, space);
}
TreeNode* lowestCommonAncestorInBst(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root ) return root;

    if(p->val < root->val && q->val < root->val) return lowestCommonAncestorInBst(root->left,p,q);
    if(p->val > root->val && q->val > root->val) return lowestCommonAncestorInBst(root->right,p,q);
    return root;
}
int main(){

    // Constructing BST:
    //
    //          8
    //        /   \
    //       3     10
    //      / \      \
    //     1   6      14
    //        / \     /
    //       4   7   13

    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    cout << "BST:\n";
    printTree(root);

    // Choose nodes whose LCA we want to find
    TreeNode* p = root->left->right->left;   // Node 4
    TreeNode* q = root->left->right->right;  // Node 7

    TreeNode* lca = lowestCommonAncestorInBst(root, p, q);

    cout << "\n\nNode 1: " << p->val;
    cout << "\nNode 2: " << q->val;

    if(lca){
        cout << "\nLowest Common Ancestor: "
            << lca->val << endl;
    }

    return 0;
}
