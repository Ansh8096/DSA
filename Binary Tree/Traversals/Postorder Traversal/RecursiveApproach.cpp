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
void traverse3(vector<int>& a, TreeNode* node){
    if(node == NULL) return;
    traverse3(a,node->left);
    traverse3(a,node->right);
    a.push_back(node->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int>ans;
    traverse3(ans,root);
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

    vector<int> result = postorderTraversal(root);

    // Print result
    cout << "Postorder Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
