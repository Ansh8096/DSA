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
bool validateBstAndFindMaxSum(TreeNode* root, int &sum, int mini, int maxii){
    if(!root) return true;
    
    if(root->val > mini && root->val < maxii) sum += root->val;
    else return false;
    
    bool l = validateBstAndFindMaxSum(root->left,sum,mini,root->val);
    if(!l) return false;
    
    bool r = validateBstAndFindMaxSum(root->right,sum,root->val,maxii);
    return r;
}
void traverseAndFindBst(TreeNode* root, int& maxSum){
    if(!root) return;
    int sum = 0;
    bool x = validateBstAndFindMaxSum(root, sum, INT_MIN, INT_MAX);
    if(x) maxSum = max(maxSum,sum);
    traverseAndFindBst(root->left,maxSum);
    traverseAndFindBst(root->right,maxSum);
}
int maxSumBST_BR(TreeNode* root) {
    int maxSum = 0;
    traverseAndFindBst(root,maxSum);
    return maxSum;
}
int main(){

    // Constructing Binary Tree:
    //
    //              1
    //            /   \
    //           4     3
    //          / \   / \
    //         2   4 2   5
    //                \   \
    //                 4   6
    //
    // Maximum Sum BST is:
    //
    //        3
    //       / \
    //      2   5
    //       \   \
    //        4   6
    //
    // Sum = 20

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(4);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);

    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);

    cout << "Binary Tree:\n";
    printTree(root);

    int ans = maxSumBST_BR(root);

    cout << "\nMaximum Sum BST = " << ans << endl;

    return 0;
}
