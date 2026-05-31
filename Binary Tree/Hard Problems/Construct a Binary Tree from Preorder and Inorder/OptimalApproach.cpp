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
TreeNode* buildTheUniqueBinaryTree(vector<int> &in, int inSt, int inEnd, vector<int>&pre, int preSt, int preEnd, unordered_map<int,int>&mpp){
    if(inSt > inEnd || preSt > preEnd) return NULL;

    TreeNode* root = new TreeNode(pre[preSt]);
    int inRoot = mpp[pre[preSt]];
    int numsLeft = inRoot - inSt;

    // left nodes...
    root->left = buildTheUniqueBinaryTree(in,inSt,inRoot-1,pre,preSt+1,preSt+numsLeft,mpp);

    // right nodes...
    root->right = buildTheUniqueBinaryTree(in,inRoot+1,inEnd,pre,preSt+numsLeft+1,preEnd,mpp);

    return root;
}
TreeNode* buildTreeFromPreAndIn(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    unordered_map<int,int> mpp;
    for (int i = 0; i < n; i++) mpp[inorder[i]] = i;
    
    TreeNode* root = buildTheUniqueBinaryTree(inorder,0,n-1,preorder,0,n-1,mpp);
    return root;
}
int main(){
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};

    TreeNode* root = buildTreeFromPreAndIn(preorder, inorder);

    printTree(root);
    
    return 0;
}
