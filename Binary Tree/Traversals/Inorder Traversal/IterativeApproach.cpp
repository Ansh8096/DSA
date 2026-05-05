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
vector<int> inorderIterativeTraversal(TreeNode* root) {
    if(root == NULL) return {};
    vector<int> ans;
    stack<TreeNode*> stk;
    TreeNode* node = root;
    while (true){
        if(node != NULL){
            stk.push(node);
            node = node->left; 
        }
        else{
            if(stk.empty() == true) break;
            TreeNode* toped = stk.top(); 
            stk.pop();
            ans.push_back(toped->val);
            node = toped->right;
        }
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
    vector<int> result = inorderIterativeTraversal(root);

    // Print result
    cout << "Inorder Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
