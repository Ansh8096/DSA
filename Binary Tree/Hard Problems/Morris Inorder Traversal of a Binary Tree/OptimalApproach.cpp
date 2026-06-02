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
vector<int> morrisInorderTraversal(TreeNode *root){
    if(!root) return {};
    vector<int> ans;
    TreeNode* curr = root;
    while (curr != NULL) {
        if(curr->left == NULL){
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode *temp = curr->left;
            while (temp->right && temp->right != curr){
                temp = temp->right;
            }
            if(temp->right == NULL){
                temp->right = curr;
                curr = curr->left;
            }
            else{  // when: (temp.right == curr) 
                temp->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return ans;
}
int main(){
    
    // Constructing tree:
    //
    //         3
    //        / \
    //       9   20
    //          /  \
    //         15   7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> ans = morrisInorderTraversal(root);

    cout<<"Morris Inorder Traversal: "<<endl;
    for (int i = 0; i < ans.size(); i++) cout<<ans[i]<< " ";
    
    return 0;
}
