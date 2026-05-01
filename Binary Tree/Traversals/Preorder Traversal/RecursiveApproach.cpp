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
void traverse(vector<int>& a, TreeNode* node){
    if(node == NULL) return;
    a.push_back(node->val);
    traverse(a,node->left);
    traverse(a,node->right);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    traverse(ans,root);
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
    vector<int> result = preorderTraversal(root);

    // Print result
    cout << "Preorder Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
