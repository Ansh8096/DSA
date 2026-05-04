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
vector<int> preorderIterativeTraversal(TreeNode* root) {
    if(root == NULL) return {};
    vector<int> ans;
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()){
        TreeNode* node = stk.top();
        stk.pop();
        ans.push_back(node->val);
        if(node->right != NULL) stk.push(node->right);
        if(node->left != NULL) stk.push(node->left);
    }
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

    // Call preorder traversal
    vector<int> result = preorderIterativeTraversal(root);

    // Print result
    cout << "Preorder Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
