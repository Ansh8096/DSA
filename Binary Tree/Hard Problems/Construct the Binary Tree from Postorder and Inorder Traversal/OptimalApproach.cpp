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
TreeNode* buildTheUniqueBinaryTree_2(vector<int> &in, int inSt, int inEnd, vector<int>&post, int postSt, int postEnd, unordered_map<int,int>&mpp){
    if(inSt > inEnd || postSt > postEnd) return NULL;

    TreeNode* root = new TreeNode(post[postEnd]);
    int inRoot = mpp[post[postEnd]];
    int numsLeft = inRoot - inSt;

    // left nodes...
    root->left = buildTheUniqueBinaryTree_2(in,inSt,inRoot-1,post,postSt,postSt+numsLeft-1,mpp);

    // right nodes...
    root->right = buildTheUniqueBinaryTree_2(in,inRoot+1,inEnd,post,postSt+numsLeft,postEnd-1,mpp);

    return root;
}
TreeNode* buildTreeFromInAndPost(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    unordered_map<int,int> mpp;
    for (int i = 0; i < n; i++) mpp[inorder[i]] = i;
    
    return buildTheUniqueBinaryTree_2(inorder,0,n-1,postorder,0,n-1,mpp);
}
int main(){
    // Tree:
    //         3
    //        / \
    //       9   20
    //          /  \
    //         15   7

    vector<int> inorder   = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode* root = buildTreeFromInAndPost(inorder, postorder);

    cout << "Constructed Tree:\n";
    printTree(root);
    
    return 0;
}
