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
vector<int> postorderIterativeTraversal(TreeNode* root) {
    if(root == NULL) return {};
    vector<int> ans;
    stack<TreeNode*> stk1;
    stack<int> stk2;
    stk1.push(root);
    while (!stk1.empty()){
        TreeNode* node = stk1.top();
        stk1.pop();
        stk2.push(node->val);
        if(node->left != NULL) stk1.push(node->left);
        if(node->right != NULL) stk1.push(node->right);
    }

    while (!stk2.empty()){
        ans.push_back(stk2.top());
        stk2.pop();
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
    vector<int> result = postorderIterativeTraversal(root);

    // Print result
    cout << "Postorder Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
