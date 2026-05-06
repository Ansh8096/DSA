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
void preorderInorderPostorderTraversal(TreeNode* root, vector<int>& preorder, vector<int>& inorder, vector<int>& postorder){
    stack<pair<TreeNode*, int>> stk;
    stk.push({root, 1});
    if(root == NULL) return;
    while (!stk.empty()){
        auto it = stk.top();
        stk.pop();

        // for preorder...
        if(it.second == 1){
            preorder.push_back(it.first->val);
            it.second++;
            stk.push(it);
            if(it.first->left != NULL) stk.push({it.first->left , 1});
        }

        // for inorder...
        else if(it.second == 2){
            inorder.push_back(it.first->val);
            it.second++;
            stk.push(it);
            if(it.first->right != NULL) stk.push({it.first->right , 1});
        }

        // for postorder...
        else{
            postorder.push_back(it.first->val);
            // don't push the element back...
        }
    }
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

    vector<int> preorder, inorder, postorder;
    // Call preorder traversal
    preorderInorderPostorderTraversal(root,preorder,inorder,postorder);

    // Print result
    cout << "Preorder Traversal: ";
    for(int val : preorder) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder Traversal: ";
    for(int val : inorder) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder Traversal: ";
    for(int val : postorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
