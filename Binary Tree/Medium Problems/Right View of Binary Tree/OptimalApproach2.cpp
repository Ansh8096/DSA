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
void recursiveRightTraverse(TreeNode* node, int level, vector<int>&ans){
    if(node == NULL) return;
    if(ans.size() == level) ans.push_back(node->val);
    recursiveRightTraverse(node->right, level+1, ans);
    recursiveRightTraverse(node->left, level+1, ans);
}
vector<int>rightViewOfBinaryTreeRecursive_OP2(TreeNode* root){
    if(root == NULL) return {};
    vector<int>ans;
    recursiveRightTraverse(root,0, ans);
    return ans;
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
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = rightViewOfBinaryTreeRecursive_OP2(root);

    // Print result
    cout << "Right view of Binary Tree: " << endl;
    for(auto val : result) {
        cout << val << " ";
    }

    return 0;
}
