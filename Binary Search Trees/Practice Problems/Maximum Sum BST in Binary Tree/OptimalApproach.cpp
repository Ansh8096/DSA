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
class NodeValue{
    public:
    int sum, maxii, mini;
    public:
    NodeValue(int sum_, int maxii_ , int mini_){
        sum = sum_;
        maxii = maxii_;
        mini = mini_;    
    }
};
NodeValue* maximumBstHelper(TreeNode* root, int& maxSum){

    if(!root){
        return new NodeValue(0,INT_MIN, INT_MAX);
    }
    
    NodeValue* l = maximumBstHelper(root->left, maxSum);
    NodeValue* r = maximumBstHelper(root->right, maxSum);
    
    if(l->maxii < root->val && root->val < r->mini){
        int sum = root->val + l->sum + r->sum;
        int maxii = max(root->val, r->maxii);
        int mini = min(root->val, l->mini);

        maxSum = max(maxSum,sum);
        return new NodeValue(sum, maxii, mini);
    }
    else{
        int sum = max(r->sum,l->sum);
        return new NodeValue(sum, INT_MAX, INT_MIN); 
    }
}
int maxSumBST_OP(TreeNode* root) {
    int maxSum = 0;
    NodeValue* nodeValue = maximumBstHelper(root,maxSum);
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
    //              /   / \
    //             -   4   6
    //
    // Maximum Sum BST:
    //
    //        3
    //       / \
    //      2   5
    //         / \
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

    int ans = maxSumBST_OP(root);

    cout << "\nMaximum Sum BST = " << ans << endl;

    return 0;
}
