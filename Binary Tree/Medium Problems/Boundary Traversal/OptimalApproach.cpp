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
bool isLeaf(TreeNode* root){
    return (root && root->left == NULL && root->right == NULL);
}
void addLeftNodes(TreeNode* root, vector<int>& ans){
    TreeNode* node = root->left;
    while (node)
    {
        if(!isLeaf(node)) ans.push_back(node->val); 
        if(node->left) node = node->left;
        else node = node->right;
    }  
}
void addLeafNodes(TreeNode* root, vector<int>& ans){
    if(isLeaf(root)){
        ans.push_back(root->val);
        return;
    } 
    if(root->left)addLeafNodes(root->left,ans);
    if(root->right)addLeafNodes(root->right,ans);
}
void addrightNodes(TreeNode* root, vector<int>& ans){
    TreeNode* node = root->right;
    vector<int>temp;
    while (node)
    {
        if(!isLeaf(node)) temp.push_back(node->val);
        if(node->right){
            node = node->right;
        }
        else node = node->left;
    }  

    reverse(temp.begin(),temp.end());
    ans.insert(ans.end(), temp.begin(),temp.end());
}
vector<int> boundaryTraversal_OP(TreeNode*root) {
    if(!root) return {};
    vector<int>ans;
    if(!isLeaf(root)) ans.push_back(root->val);
    addLeftNodes(root,ans);
    addLeafNodes(root,ans);
    addrightNodes(root,ans);
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
    
    vector<int> result = boundaryTraversal_OP(root);

    // Print result
    cout << "Boundary Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
