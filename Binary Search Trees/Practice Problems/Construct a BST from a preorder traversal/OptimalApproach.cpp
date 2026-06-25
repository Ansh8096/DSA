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

    // Increase distance between levels:
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
TreeNode* traverseAndBuildBst_2(vector<int>& pre, int& idx, int n, int ub){
    if(idx>=n || pre[idx] > ub) return NULL;

    TreeNode* newNode = new TreeNode(pre[idx]);
    idx += 1;
    newNode->left = traverseAndBuildBst_2(pre,idx,n,newNode->val);
    newNode->right = traverseAndBuildBst_2(pre,idx,n,ub);
    return newNode;
}
TreeNode* bstFromPreorder_OP(vector<int>& pre) {
    int idx = 0;
    return traverseAndBuildBst_2(pre, idx, pre.size(), INT_MAX);
}
int main(){

    // Preorder traversal of a BST
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    cout << "Preorder Array:\n";
    for(int x : preorder){
        cout << x << " ";
    }
    cout << "\n\n";

    TreeNode* root = bstFromPreorder_OP(preorder);

    cout << "Constructed BST:\n";
    printTree(root);

    return 0;
}
